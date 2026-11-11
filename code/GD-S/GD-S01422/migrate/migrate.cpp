#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=5e3+10;
#define ll long long
ll c,t,n,d,a[N];
//0表距离，1表数量 
ll f[N][N][2];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ll ans=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[i-1]<=d){
				f[i-1][i][0]=1;
				f[i-1][i][1]=1;
			}
			else f[i-1][i][0]=1e9;
		}
		for(ll len=3;len<=n;len++){
			for(ll l=1;l<=n-len+1;l++){
				f[l][l+len-1][0]=1e9;
				f[l][l+len-1][1]=0;
				for(ll mid=l+1;mid<(l+len-1);mid++){
					if(a[l+len-1]-a[l]<=d){
						f[l][l+len-1][0]=1;
						f[l][l+len-1][1]=1;
						break;
					}
					if(a[mid]-a[mid-1]<=d){
						ll dis=f[l][mid][0]+f[mid][l+len-1][0];
						if(f[l][l+len-1][0]>dis){
							f[l][l+len-1][0]=dis;
							f[l][l+len-1][1]=f[l][mid][1]*f[mid][l+len-1][0];
						}
						else if(f[l][l+len-1][0]==dis){
							f[l][l+len-1][1]+=f[l][mid][1]*f[mid][l+len-1][0];
						}
					}
				}
				if(f[l][l+len-1][1]==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
