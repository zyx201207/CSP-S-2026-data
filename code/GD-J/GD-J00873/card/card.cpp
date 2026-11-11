#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=5e5+5,M=3e5+5;
const int INF=0x3f3f3f3f,MOD=1e9+7;
typedef long long LL;
int n,m,a[N],cnt[M],r,ans[M];
bool vis[M];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],cnt[a[i]]++;
	for(int i=1;i<=n;i++)
		if(cnt[a[i]]>1)r = i;
	for(int i=1;i<=n;i++){
		int pos=0;
		for(int j=i;j<=n;j++)
			if(cnt[a[j]]>1){
				pos = j;
				break;
			}
//		cout<<pos<<endl;
		if(!pos){
			for(int j=i;j<=n;j++)
				ans[a[j]]+=j-i+1;
			break;
		}
		memset(vis,0,sizeof vis);
		for(int j=i;j<=pos;j++)
			vis[a[j]] = 1;
		for(int j=r;j<=n;j++)
			vis[a[j]] = 1;
		for(int j=1;j<=m;j++)
			ans[j]+=vis[j]; 
		cnt[a[i]]--;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i!=m)cout<<" "; 
	}
	return 0;
}
