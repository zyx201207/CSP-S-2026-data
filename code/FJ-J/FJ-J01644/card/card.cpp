#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,m;
int a[maxn],b[maxn],ans[maxn];
int lst[maxn];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		lst[i]=n+1;
	}
	for(int i=n;i;i--){
		if(lst[a[i]]>n){
			lst[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		b[i]++;
		if(lst[a[i]]==i){
			b[i+1]+=b[i];
		}else{
			b[lst[a[i]]+1]+=b[i];
		}
		ans[a[i]]+=b[i];
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}
