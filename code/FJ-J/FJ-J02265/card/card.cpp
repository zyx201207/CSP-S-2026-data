#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
struct Node{
	int cnt,num;
};
int n,m;
int a[N];
int inq[N];
int ans[N];
void game(int x){
	for(int i=x;i<=n;i++){
		if(inq[a[i]]!=0){
			for(int j=inq[a[i]];j<i;j++){
				inq[a[j]]=0;
			}
		}
		inq[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		ans[i]+=(inq[i]!=0);
		inq[i]=0;
	}
	return;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		game(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int T=1;
	while(T--)solve();
	return 0;
}
