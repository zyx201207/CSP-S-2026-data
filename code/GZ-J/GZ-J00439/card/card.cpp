//GZ-J00439 贵阳市第一中学 徐錦鴻 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005],d[300005],vis[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(d[a[i]]&&!vis[d[a[i]]]){
			for(int j=d[a[i]];j<i;j++){
				vis[j]=1;
				cnt[a[j]]+=i-j;
			}
		} 
		d[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]) cnt[a[i]]+=n-i+1;
	}
	for(int i=1;i<=m;i++) cout<<cnt[i];
	return 0;
}
