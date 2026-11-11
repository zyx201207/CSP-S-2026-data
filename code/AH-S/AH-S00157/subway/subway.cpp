#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
const int inf=2e9;
const int mod=1e9+7;
int c,n,m,dd,qwq;
int val[N];
vector <int> a[N];
vector <int> t[N];
int tu[2000][2000];
int fnd(int x,int y){
	int mn=mod;
	for(int s1=0;s1<a[x].size();s1++){
		for(int s2=0;s2<a[y].size();s2++) if(s1!=s2){
			if(a[x][s1]==a[y][s2]){
				mn=min(mn,t[x][a[x][s1]]+t[y][a[y][s2]]);
			}
		}
	}
	return mn;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	cin >> c >> n >> m >> dd >> qwq;
	for(int i=1;i<=m;i++){
		cin >> val[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int ls,tt;
			cin >> ls >> tt;
			a[ls].push_back(i);
			t[ls].push_back(tt);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			tu[i][j]=mod;
		}
	}
	for(int i=1;i<=m;i++){
		for(int s1=0;s1<a[i].size();s1++){
			for(int s2=0;s2<a[i].size();s2++) if(s1!=s2){
				tu[ a[i][s1] ][ a[i][s2] ]=min(tu[ a[i][s1] ][ a[i][s2] ],t[i][s1]+t[i][s2]);
			}
		}
	}
	while(qwq--){
		int x,y,ans=mod;
		cin >> x >> y;
		for(int s1 : a[x]){
			for(int s2 : a[y]){
				if(s1==s2) ans=fnd(x,y);
				ans=min(ans,tu[s1][s2]);
			}
		}
		cout << ans+val[x]+val[y] << endl;
	}
	return 0;
}

