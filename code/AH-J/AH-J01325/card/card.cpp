#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005],c[500005],f[500005];
int cnt[500005],dad[500005],ans[500005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>0;i--){
		if(i==n){
			dad[i]=0,b[i]=a[i],cnt[a[i]]=i;
			continue;
		}
		if(cnt[a[i]])dad[i]=cnt[a[i]],f[cnt[a[i]]]++;
		else dad[i]=i+1,f[i+1]++,b[i]=a[i];
		cnt[a[i]]=i;
	}
	queue<int> q;
	for(int i=1;i<=n;i++)if(f[i]==0)q.push(i);
	while(!q.empty()){
		int g=q.front();
		q.pop();
		c[g]++;
		ans[b[g]]+=c[g];
		f[dad[g]]--,c[dad[g]]+=c[g];
		if(f[dad[g]]==0)q.push(dad[g]);
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
