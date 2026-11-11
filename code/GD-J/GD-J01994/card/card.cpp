#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5*1e5+5,M=3*1e5+5;
int n,m;
int a[N],b[M],nxt[N];
int s[N],ans[M];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=1;
	}
	for(int i=n;i>=1;i--){
		if(b[a[i]]==0){
			b[a[i]]=i;
			nxt[i]=i+1;
		}else{
			nxt[i]=b[a[i]];
		}
	}
	for(int i=1;i<=n;i++){
		s[nxt[i]]+=s[i];
		if(b[a[i]]==i){
			ans[a[i]]=s[i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	return 0;
}
