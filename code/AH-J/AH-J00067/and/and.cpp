#include<bits/stdc++.h>
using namespace std;
#define int long long
int ai[200010],t[200010];
int be(int a,int w){
	return a&(1<<w);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	map<int,int>l;
	for(int x=1;x<=n;x++){
		cin>>ai[x];
		t[x]=1;
	}
	sort(ai+1,ai+n+1);
	int ans=0;
	for(int x=29;x>=0;x--){
		int tt=0;
		for(int y=1;y<=n;y++){
			if(t[y]&&be(ai[y],x))tt++;
		}
		if(tt>=m){
			ans+=(1<<x);
			for(int y=1;y<=n;y++){
				if(t[y]&&!be(ai[y],x))t[y]=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
