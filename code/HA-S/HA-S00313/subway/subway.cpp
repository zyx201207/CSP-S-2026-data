#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,p,T,ans;
vector<ll> w;
vector<ll> way[50005];
ll station[10005][10005];
ll t[10005][10005];
void f(){
	bool m=0;
	ll x,y;
	cin>>x>>y;
	if(station[x][y]!=0){
		ans=w[x-1]+w[y-1]+t[station[x][y]][x]+t[station[x][y]][y];
		cout<<ans<<endl;
		return;
	}
	else{
		for(int i=1;i<=n;i++){
			if(i==x || i==y) continue;
			if(station[x][i]!=0 && station[y][i]!=0){
				m=1;
				ans=min(ans,w[x-1]+w[y-1]+t[station[x][i]][x]+t[station[x][i]][i]+t[station[y][i]][i]+t[station[y][i]][y]);
				
			}
		}
		if(m){
				cout<<ans<<endl;
				return;
		}
			
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==x || i==y || j==i || j==x || j==y ||station[i][j]==0) continue;
				if(station[x][i]!=0 && station[y][j]!=0){
					m=1;
					ll mm=w[x-1]+w[y-1]+t[station[x][i]][x]+t[station[x][i]][i]+t[station[i][j]][i]+t[station[i][j]][j]+t[station[y][j]][j]+t[station[y][j]][y];
					ans=min(ans,mm);
				}
				
			}
		}
		if(m){
			cout<<ans<<endl;
			return;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int ii=1;ii<=n;ii++){
					if(station[x][i]!=0 && station[i][j]!=0 && station[j][ii]!=0 && station[ii][y]!=0){
						m=1;
						ll mm=w[x-1]+w[y-1]+t[station[x][i]][x]+t[station[x][i]][i]+t[station[i][j]][i]+t[station[i][j]][j]+t[station[j][ii]][j]+t[station[j][ii]][ii]+t[station[ii][y]][ii]+t[station[ii][y]][y];
						ans=min(ans,mm);
					}
				}
			}
		}
		if(m){
			cout<<ans<<endl;
			return;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int ii=1;ii<=n;ii++){
					for(int jj=1;jj<=n;jj++){
						if(station[x][i]!=0 && station[i][j]!=0 && station[j][ii]!=0 && station[ii][jj]!=0 && station[jj][y]!=0){
							ll a1=station[x][i],a2=station[i][j],a3=station[j][ii],a4=station[ii][jj],a5=station[jj][y];
							m=1;
							ll mm=w[x-1]+w[y-1]+t[a1][x]+t[a1][i]+t[a2][i]+t[a2][j]+t[a3][j]+t[a3][ii]+t[a4][ii]+t[a4][jj]+t[a5][jj]+t[a5][y];
							ans=min(ans,mm);
						}
					}
				}
			}
		}
		if(m){
			cout<<ans<<endl;
			return;
		}
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int ii=1;ii<=n;ii++){
					for(int jj=1;jj<=n;jj++){
						for(int iii=1;iii<=n;iii++){
							if(station[x][i]!=0 && station[i][j]!=0 && station[j][ii]!=0 && station[ii][jj]!=0 && station[jj][iii]!=0 && station[iii][y]!=0){
								ll a1=station[x][i],a2=station[i][j],a3=station[j][ii],a4=station[ii][jj],a5=station[jj][iii],a6=station[iii][y];
								m=1;
							ll mm=w[x-1]+w[y-1]+t[a1][x]+t[a1][i]+t[a2][i]+t[a2][j]+t[a3][j]+t[a3][ii]+t[a4][ii]+t[a4][jj]+t[a5][jj]+t[a5][iii]+t[a6][iii]+t[a6][y];
							ans=min(ans,mm);
							}
						}
					}
				}
			}
		}
		if(m){
			cout<<ans<<endl;
			return;
		}
		
				for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int ii=1;i<=n;ii++){
					for(int jj=1;jj<=n;jj++){
						for(int iii=1;iii<=n;iii++){
							for(int jjj=1;jjj<=n;jjj++){
								if(station[x][i]!=0 && station[i][j]!=0 && station[j][ii]!=0 && station[ii][jj]!=0 && station[jj][iii]!=0 && station[iii][jjj]!=0 && station[jjj][y]!=0){
								ll a1=station[x][i],a2=station[i][j],a3=station[j][ii],a4=station[ii][jj],a5=station[jj][iii],a6=station[iii][jjj],a7=station[jjj][y];
								m=1;
							ll mm=w[x-1]+w[y-1]+t[a1][x]+t[a1][i]+t[a2][i]+t[a2][j]+t[a3][j]+t[a3][ii]+t[a4][ii]+t[a4][jj]+t[a5][jj]+t[a5][iii]+t[a6][iii]+t[a6][jjj]+t[a7][jjj]+t[a7][y];
							ans=min(ans,mm);
								
							}
						}
					}
				}
			}
		}
	}
	if(m){
			cout<<ans<<endl;
			return;
		}
		
	}

	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		ll x;
		cin>>x;
		w.push_back(x);
	}
	for(int i=1;i<=n;i++){
		ll num;
		cin>>num;
		for(int j=1;j<=num;j++){
			ll a,b;
			cin>>a>>b;
			T=b;
			t[i][a]=b;
			way[i].push_back(a);
		}
		for(int j=0;j<way[i].size()-1;j++){
			for(int jj=j+1;jj<way[i].size();jj++){
				station [way[i][jj]] [way[i][j]]=i;
				station [way[i][j]] [way[i][jj]]=i;
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cout<<station[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	while(p>0){
		p--;
		ans=999999999;
		f();
	}
	return 0;
}
/*
纯粹图论角度没什么思路，特殊性质也写不出来，主要是多组数据捆绑太烦人了
干脆存好数据后换乘1次，2次，3次 ...
数据善待我 
0 1 2 100 2
10 10
2 1 10 2 10
1 2
2 1

0 3 6 100 1
10 10 10 10 10 10
3 1 10 2 10 4 10
3 2 10 3 10 5 10
2 3 10 6 10
4 6

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3 
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
