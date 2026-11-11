#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long

int const N=5e5+10;
int n,m,an[N],top,st[N],lst[N],ans[N];
bool vis[N];

bool check(){
	for(int i=2;i<=n;i++){
		if(an[i]<an[i-1]) return 0;
	}
	return 1;
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>an[i];
	if(check()){
		for(int i=2;i<=n;i++){
			if(an[i]!=an[i-1]) cout<<i-1<<" ";
		}
		cout<<n;
		return ;
	}
	if(n<=5e3){
		for(int i=1;i<=n;i++){
			top=0;
			for(int j=1;j<=m;j++) vis[j]=0;
			for(int j=i;j<=n;j++){
				if(vis[an[j]]){
					while(st[top]!=an[j]) vis[st[top--]]=0;
				}
				else st[++top]=an[j],vis[an[j]]=1;
			}
			for(int j=1;j<=top;j++) ans[st[j]]++;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i];
			if(i!=m) cout<<' ';
		}
		return ;
	}
	for(int i=n;i>=1;i--){
		if(!lst[an[i]]) lst[an[i]]=i;
	}
	for(int i=n;i>=1;i--){
		int pos=i;
		while(pos<=n) ans[an[pos]]++,pos=lst[an[pos]]+1;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i!=m) cout<<' ';
	}
	return ;
}

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
	return 0;
}

