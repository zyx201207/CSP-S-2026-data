#include<bits/stdc++.h>
using namespace std;
long long a[500005],top=0;
long long s[500005];
long long vis[500005],d[500005],cnt[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			if(vis[a[i]]){
				while(s[top]!=a[i]) vis[s[top--]]=0;
			}else vis[a[i]]=1,s[++top]=a[i];
		}
		while(top!=0){
			cnt[s[top]]++;
			top--;
		}
		for(int i=1;i<=m;i++) vis[i]=0;
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
