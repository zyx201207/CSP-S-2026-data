#include <iostream>
#include <string> 
using namespace std;
struct node{
	long long a;
	char c;
};
node a[214514];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sum=0;
	long long ans=0;
	char m;
	cin>>n;
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
	}
	while((n--)){
		if(n==0){
		}
		if(sum<0){
			if(m!=a[l].c){
				ans+=min(a[l].a,(0-sum));
			}
			if((-sum)<a[l].a){
				/*
				if(m!=a[l].c){
					ans+=(-sum);
				}
				*/
				m=a[l].c;
			}
			else{
				/*
				if(m!=a[l].c){
					ans+=(-sum);
				}
				*/
			}
			sum+=a[l].a;
			l++;
		}
		else{
			if(m!=a[r].c){
				ans+=min(a[r].a,sum);
			}
			if(sum<a[r].a){
				/*
				if(m!=a[l].c){
					ans+=(-sum);
				}
				*/
				m=a[r].c;
			}
			sum-=a[r].a;
			r--;
		}
		//cout<<sum<<" "<<m<<endl;
		//cout<<ans<<'\n';
	}
	cout<<ans;
	return 0;
}
