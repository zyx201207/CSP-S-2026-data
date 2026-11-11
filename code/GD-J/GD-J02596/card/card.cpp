#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],cnt[300005];
bool vis[300005];
int main(){
	//while(1);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			//cout<<i<<' '<<j<<"\n";
			if(vis[a[j]]){
				for(int k=0;k<=300005;k++)vis[k]=0;
			}
			vis[a[j]]=1;
		}
		for(int k=0;k<=300005;k++)cnt[k]+=vis[k],vis[k]=0;
	}
	for(int i=1;i<=300005;i++)if(cnt[i])cout<<cnt[i]<<' ';
	return 0;
}
