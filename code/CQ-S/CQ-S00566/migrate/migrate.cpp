#include<bits/stdc++.h>
#define N 2000005
using namespace std;
namespace shan{
	typedef long long ll;
	int C,T;
	int n,to[N][3];
	ll d,x[N],dans[N][2];
	int t[N][4];
    signed main(){
		cin>>C>>T;
		while(T--){
			cin>>n>>d;
			for(int i=1;i<=n;i++)cin>>x[i];
			for(int i=1,j=1;i<=n;i++){
				t[i][0]=t[i][1]=t[i][2]=t[i][3]=0;
				while(j<n&&x[j+1]-x[i]<=d)j++;
				to[i][0]=j;
				to[i][1]=max(0,j-1);
				to[i][2]=max(0,j-2);
			}
			ll ans=0,ex=0;
			for(int i=1;i<=n;i++){
				if(i==to[i][0])continue;
				t[to[i][0]][3]++;
				for(int j=0;j<4;j++){
					if(!t[i][j])continue;
					int f[3]={i,i-(j&2)/2,i-(j&2)/2-(j&1)};
					int nf[3];
					nf[0]=to[f[0]][0];
					nf[1]=max(to[f[1]][0],to[f[0]][1]);
					nf[2]=max({to[f[0]][2],to[f[1]][1],to[f[2]][0],
						min(to[f[1]][0],to[f[0]][1])});
					ans+=(ll)t[i][j]*max(0,to[f[1]][0]-max(f[0],to[f[2]][0]));
					t[nf[0]][(nf[0]!=nf[1])*2+(nf[1]!=nf[2])]+=t[i][j];
				}
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    shan::main();
    return 0;
}
/*
g++ migrate.cpp -o migrate.exe -Wall -Wextra -static -std=c++14 -O2 
./migrate.exe
*/