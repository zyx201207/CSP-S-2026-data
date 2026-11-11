#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
int n,m,a[5005];
int pos[5005],p[5005],ans[5005],idx[5005],cnt[5005];
bool cmp(int x,int y){
	return p[x]<p[y];
}
//priority<pii,vector<pii>,greater<pii>>q;
bool vis[5005];
int stk[5005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool flag=0;
	for(int i=n;i>=1;i--){
		int tot=0;
		flag=1^flag;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==flag){
				while(tot>=0&&stk[tot]!=a[j]){
					cnt[stk[tot]]--;
					tot--;
				}
			}
			else{
				stk[++tot]=a[j];
				cnt[a[j]]++;
			}
			vis[a[j]]=flag;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
//10 3 3 1 2 1 3 2 3 1 2 1
