#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m;
int a[N];
vector<int> ve[N];
int cnt[N]; 
stack<int> stk;
int ans[N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			while(cnt[a[j]]>=1){
				int tmp=stk.top();
				cnt[tmp]--;
				stk.pop();
			}
			cnt[a[j]]++;
			stk.push(a[j]);
		}
		for(int j=1;j<=m;j++) if(cnt[j]>=1) ans[j]++,cnt[j]=0;
		while(stk.size()) stk.pop();
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return ;
} 
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int oT_To=1;
//   cin>>oT_To;
	while(oT_To--) solve();
	return 0;
}
