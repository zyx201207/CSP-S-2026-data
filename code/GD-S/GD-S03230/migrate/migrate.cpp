#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d;
int a[2000005];
vector<int>g[2000005];
int f[2000006];//从1结点到i的距离
int t[2000006];//从1到i的最短路径条数 
void solve(){
	cin>>n>>d;
	//cout<<d<<endl;
	for(int i=0;i<=5000;i++)
		g[i].clear();   
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d){
				g[j].push_back(i);//反图 
			}else{
				break;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		memset(f,0x3f,sizeof f);
		memset(t,0,sizeof t);
		f[i]=0,t[i]=1;
		for(int j=i+1;j<=n;j++){
			int mi=1e9;
			for(int v:g[j]){
				if(v<i) continue;
				mi=min(mi,f[v]);
			}
			f[j]=mi+1;
			for(int v:g[j]){
				if(v<i) continue;
				if(f[v]==mi){
					t[j]+=t[v];
				}
			}
			if(t[j]==2) ans++;
		}
	}
	cout<<ans<<'\n';
}
void solve1(){//等差数列时 
	cin>>n>>d; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int D=a[2]-a[1];
	if(d<2*D){
		cout<<0<<endl;
	}else{
		int k=d/D;
		cout<<(k-1)*n-(k+4)*(k-1)/2<<endl;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate9.in","r",stdin);
	int c,t;
	cin>>c>>t;
	while(t--){
		if(c==11||c==12) solve1();
		else solve();
	}
} 
/*
8 3
0 1 2 4 8 10 11 13
1
4 3
0 1 2 4 
*/

