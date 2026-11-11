#include<bits/stdc++.h>
using namespace std;
struct s{
	char c;
	long long cnt;
};
s a[200010];
long long n,sum,ans,l,r,t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].c;
		//sum+=a[i].cnt;
	}
	//long long mid=(sum%2==0)?sum/2:sum/2+1;
	l=0;i=1;r=n;t=0;
	while(l<r){//check this
		if(a[l].c==a[r].c){
			if(a[l].cnt>=a[r].cnt){
				a[l].cnt-=a[r].cnt;
				a[r].cnt=0;
				r--;
			}
			else{
				a[r].cnt-=a[l].cnt;
				a[l].cnt=0;
				l++;
			}
		}
		else{
			if(a[l].cnt>=a[r].cnt){
				a[l].cnt-=a[r].cnt;
				ans+=a[r].cnt;
				a[r].cnt=0;
				r--;
			}
			else{
				a[r].cnt-=a[l].cnt;
				ans+=a[l].cnt;
				a[l].cnt=0;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
