#include<bits/stdc++.h>
using namespace std;
long long c,t,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		long long n,d,f=1;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>2){
				if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
					f=0;
				}
			}
		}
		
		if(n==1||d==1){
			cout<<"0"<<endl;
		}
		else if(f==1){
			if(a[n]-a[n-1]>=d){
				cout<<"0"<<endl;
			}else{
				long long ans=n-d/(a[n]-a[n-1])*2+1;
				if(ans<0) ans=0;
				cout<<ans<<endl;
			}
		}
		else if(max(max(a[n/2]-a[1],a[n]-a[n/2]),max(a[n/2+1]-a[1],a[n]-a[n/2+1]))<=d){
			cout<<"0"<<endl;
		}
	}
	return 0;
}
