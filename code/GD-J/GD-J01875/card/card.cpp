#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5*1e5+10;
int n,m,a[maxn],sum[maxn],b[maxn],num[maxn],wei;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)    cin>>a[i];
	for(int i=1;i<=n;i++){
		wei=i;
		for(int j=1;j<=m;j++)    b[j]=0;
		for(int j=i;j<=n;j++){
			if(b[a[i]]==0)    b[a[i]]=j;
			else    wei=b[a[i]];
			num[wei]=a[i];
		    wei++;
		}
		for(int j=i;j<wei;j++)    sum[num[j]]++;
	}
	for(int i=1;i<=m;i++)    cout<<sum[i]<<" ";
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--)    solve();
}
