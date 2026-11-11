#include<bits\stdc++.h>
using namespace std;
long long n,m,a[500005],maxa=-10000000;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool A=true,B=true;
	cin>>n>>m;
	if(n==1){
		cout<<1<<"\n";
		return 0;
	}
	cin>>a[1]>>a[2];
	if(a[1]!=1||a[2]!=2)A=false;
	maxa=max(maxa,max(a[1],a[2]));
	long long BB=a[2]-a[1];
	for(long long i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			A=false;
		}
		if(a[i]-a[i-1]!=BB){
			B=false;
		}
		maxa=max(maxa,a[i]);
	}
	if(A){
		long long ans=1,all=0;
		for(long long i=1;;i++){
			all+=i;
			if(all>m){
				break;
			}
			ans++;
			if(ans>n){
				ans=n;
				break;
			}
		}
		cout<<ans<<"\n";
		return 0;
	}else if(B){
		long long ans=1,all=0,ii=a[2]-a[1];
		for(long long i=ii;;i+=ii){
			all+=i;
			if(all>m){
				break;
			}
			ans++;
			if(ans>n){
				ans=n;
				break;
			}
		}
		cout<<ans<<"\n";
	}else{
		long long aa=0;
		for(long long i=1;i<=n;i++){
			aa+=maxa-a[i];
		}
		if(aa<=m){
			cout<<n;
			return 0;
		}
		long long ans=1,all=0,ii=a[2]-a[1];
		for(long long i=ii;;i+=ii){
			all+=i;
			if(all>m){
				break;
			}
			ans++;
			if(ans>n){
				ans=n;
				break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
