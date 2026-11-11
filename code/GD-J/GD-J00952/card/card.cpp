#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+50,maxm=3e5+50;
stack<int>sk;
int n,m,f[maxn],ans[maxm],cnt[maxn],lst[maxn];
bool vis[maxm];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>f[i],lst[f[i]]=i;
	if(n<=6000){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(!cnt[f[j]]) sk.push(f[j]),cnt[f[j]]++;
				else while(sk.top()!=f[j]) cnt[sk.top()]--,sk.pop();
			}
			while(!sk.empty()) vis[sk.top()]=1,cnt[sk.top()]--,sk.pop();
			for(int j=1;j<=m;j++) ans[j]+=vis[j],vis[j]=0;
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	else for(int i=1;i<=m;i++) cout<<lst[i]<<" ";
	return 0;
}
