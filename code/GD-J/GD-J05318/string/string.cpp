#include<bits/stdc++.h>
using namespace std;
int n;
long long sum=0,cnt=0;
struct{
	long long c;
	char s;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].c>>a[i].s;
		sum+=a[i].c;
	}
	if(sum%2==0){
		sum=sum/2;
	}else if(sum%2==1){
		sum=(sum-1)/2;
	}
	int g=0,f=1;
	while(sum>0){
		if(a[f].c<a[n-g].c){
			a[n-g].c-=a[f].c;
			sum-=a[f].c;
			if(a[f].s!=a[n-g].s){
				cnt+=a[f].c;
			}
			f++;
		}
		else if(a[f].c==a[n-g].c){
			sum-=a[f].c;
			if(a[f].s!=a[n-g].s){
				cnt+=a[f].c;
			}
			f++;
			g++;
		}
		else if(a[f].c>a[n-g].c){
			a[f].c-=a[n-g].c;
			sum-=a[n-g].c;
			if(a[f].s!=a[n-g].s){
				cnt+=a[n-g].c;
			}
			g++;
		}
	}
	cout<<cnt;
	return 0;
} 
