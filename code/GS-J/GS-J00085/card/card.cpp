#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,char> pii;
const int N=5e5+10;
const int M=3e5+10;
int n,m,t;
int a[N];
int ans[M];
int last[M];

int cnt[M];
bool vis[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]+=1;
	}
	for(int i=n;i>=1;i--){
		if(last[a[i]]==0)last[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int idx=i;
		while(idx<=n){
			ans[a[idx]]+=1;
			idx=last[a[idx]]+1;
		}	
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
}
