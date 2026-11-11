//GZ-J00585 李博煜 华东师范大学附属贵阳学校
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt[300005];
bool vis[300005];
long long wei[300005];
void gamebeg(long long st){
	memset(vis,0,sizeof(vis));
	memset(wei,0,sizeof(wei));
	for(long long i=st;i<=n;i++){
		if(vis[a[i]]==0){
			vis[a[i]]=1;
			wei[a[i]]=i;
		}
		else{
			for(long long j=wei[a[i]];j<i;j++){
				vis[a[j]]=0;
			}
			vis[a[i]]=1;
			wei[a[i]]=i;
		}
	}
	for(long long i=1;i<=m;i++){
		cnt[i]+=vis[i];
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		gamebeg(i);
	}
	for(long long i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}

