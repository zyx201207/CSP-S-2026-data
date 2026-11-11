#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
int c,t;
ll n;
ll d;
ll a[5005];//qian 10 ge
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<=10){
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int k=i+3;k<=n;k++){
				ll f=1;
				for(int j=i;j<=k&&f<=2;j++){
					int u=j;
					int v1=u;
					while(v1+1<=k&&a[v1+1]-a[u]<=d)v1++;
					int v2=v1;
					while(v2+1<=k&&a[v2+1]-a[v1]<=d)v2++;
					if(v2==u){f*=3;continue;}
					j=v2;
					if(v2-u>=3){
						if(a[v1-1]-a[u]<=d&&a[v2]-a[v1-1]<=d){
							if(v1-2>u&&a[v1-2]-a[u]<=d&&a[v2]-a[v1-2]<=d)f*=3;
							else f*=2;
						}
					}
				}
				if(f==2)ans++;
				if(f>2)continue;
			}
		}
		cout<<ans<<endl;
	}
	}else if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>a[i];
			int l=a[2]-a[1];
			if(d/l<=1)cout<<0<<endl;
			else cout<<max((ll)0,n-(d/l+2)+1)<<endl;
			
		}
	}else{
		
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


0 1000
5 6
0 1 3 6 7
5 6
0 1 3 6 8
*/