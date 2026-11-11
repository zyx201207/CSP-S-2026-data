#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
int k;
int w[N];
vector<int> a[N],t[N];
int s[N],tar[N];
int dfs(int l,int targ,int c,int depth){
	if(c==targ) return depth;
	int minn=0x3f3f3f3f;
	for(auto r:a[c]){
		minn=min(minn,dfs(l,targ,r,depth+t[l][r]+w[a[l][r]]));
	}
	return minn;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int a1,t1;
			cin>>a1>>t1;
			a[i].push_back(a1);
			t[i].push_back(t1);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>s[i]>>tar[i];
		cout<<dfs(tar[i],s[i],0)<<endl;;
	}
	return 0;
