#include<bits/stdc++.h>
using namespace std;
const int SIZE=200005;
int a[SIZE],n,m,ans,nowc=1;
vector<int>lst[34];
int cnt;
bool cntt(int x,int k){
	return x&(1<<(32-k));
}
void dfs(int k){
	if(k==32){
		if(cnt>m){
			ans=ans<<1|1;
		}else if(cnt<m){
			ans=ans<<1;
		}else{
			int anss=INT_MAX;
			for(int i=0;i<lst[nowc].size();i++){
				if(cntt(a[lst[nowc][i]],k))
					anss&=a[lst[nowc][i]];
			}
			ans=anss;
		}
		return ;
	}
	if(cnt>m){
		cnt=0;
		nowc++;
		for(int i=0;i<lst[nowc-1].size();i++){
			if(cntt(a[lst[nowc-1][i]],k+1))
				lst[nowc].push_back(lst[nowc-1][i]);
		}
		for(int i=0;i<lst[nowc].size();i++){
			cnt+=cntt(a[lst[nowc][i]],k+1);
		}
		ans=ans<<1|1;
		dfs(k+1);
	}else if(cnt<m){
		cnt=0;
		for(int i=0;i<lst[nowc].size();i++){
			cnt+=cntt(a[lst[nowc][i]],k+1);
		}
		ans=ans<<1;
		dfs(k+1);
	}else{
		int anss=INT_MAX;
		for(int i=0;i<lst[nowc].size();i++){
			if(cntt(a[lst[nowc][i]],k))
				anss&=a[lst[nowc][i]];
		}
		ans=anss;
		return;
	}
}
signed main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		lst[nowc].push_back(i);
	}
	dfs(1);
	cout<<ans;
	return 0;
}

