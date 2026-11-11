#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+5,M=25;
int T,c,n,nx[N];
//int f[N][M];
ll d,x[N],dt[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>c>>T;
	while(T--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i],dt[i]=x[i]-x[i-1];
		x[n+1]=4e18;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n+1;j++){
				if(x[j]-x[i]>d){
					nx[i]=j-1;	
					break;
				}
			}
		}
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				 int l=u,num=0;
				 bool f=0;
				 while(l<v){
				 	int tl=min(nx[l],v);
				 	if(f&&x[tl]-x[l]+dt[l]<=d)num++;	
				 	if(l==nx[l])goto lz;
				 	f=1;
				 	l=tl;
				 }
				 if(num==1)ans++;
				 lz:;
			}
		}
		cout<<ans<<'\n';
	}
} 
