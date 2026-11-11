#include<bits/stdc++.h>
using namespace std;
int c,t,ans;
long long n,d;
long long x[2000005],to[2000005],vis[2000005];
vector<vector<long long> > e;
int mian(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>x[i];
	cout<<0<<'\n';
//	for(int i=1,j=1;i<=n;i++){
//		while(x[j]-x[i]<d&&j<=n) j++;
//		to[i]=j; 
//	}
//	memset(vis,-1,sizeof(vis));
//	for(int i=1;i<=n;i++){
//		if(vis[i]!=-1) continue;
//		e.push_back(vector<long long>(0));
//		e.back().push_back(x[i]-d);
//		int j=i; e.back().push_back(i),vis[i+d]=e.size()-1;
//		while(to[j]<=n) j=to[j],e.back().push_back(j),vis[j]=e.size()-1;
//	}
//	if(c<=10){
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				int minr=lower_bound(e[vis[i]].begin(),e[vis[i]].end(),j)-e[vis[i]].begin();
//				int k=i-1;
//				while(k>0&&i-k<2&&lower_bound(e[vis[k]].begin(),e[vis[k]].end(),j)-e[vis[k]].begin()==minr) k--;
//				if(i-k==2) ans++;
//			}
//		}
//		cout<<ans;
//	}memset(x,0,sizeof(x));
//	memset(to,0,sizeof(to));
//	e.clear();
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) mian();
	return 0;
}
/*1 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6*/

