#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
int n,m;
int a[N];
int sum[N],ans[N];
int vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)
			sum[j]=0,vis[j]=0;
		sum[i]++;
		for(int k=i;k<=n;k++){
			if(vis[a[k]]!=0){
				if(vis[a[k]]==i) sum[vis[a[k]]]--;
				 else sum[vis[a[k]]]-=2;
				sum[k]++,vis[a[k]]=k;
			}
			 else vis[a[k]]=k;
		}
		for(int j=i;j<=n;j++){
			sum[j]+=sum[j-1];
			ans[a[j]]+=sum[j];
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}

