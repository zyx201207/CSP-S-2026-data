#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000100],a[2000100],b[2000100],v;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>x[i];
			for(int i=1;i<n;i++) a[i]=x[i+1]-x[i];
			for(int i=1;i<=n;i++) x[i]--;
			if(d<2*x[2]-x[1]) cout<<0;
			else{
				n-=2;
				printf("%lld\n",n);
			}
		}
	}else{
		while(t--){
			cin>>n>>d;
			long long dd=2*d,sum=0;
			for(int i=1;i<=n;i++) cin>>x[i];
			for(int i=1;i<n;i++) a[i]=x[i+1]-x[i];
			for(int u=1;u+2<=n;u++){
				v=u+2;
				if(x[v]-x[u]<dd) sum++; 
			}sum--;
			printf("%lld\n",sum);
		}
	}
	return 0;
}
