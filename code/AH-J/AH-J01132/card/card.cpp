#include<bits/stdc++.h>
using namespace std;
int n,m,i,j;
int b[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	vector<int>a(n+1);
	for(i=1;i<=n;i++)cin>>a[i];
	vector<bool>bj(m+1);
	for(i=n;i>=1;i--){
		b[a[i]]+=i;
		if(bj[a[i]]==1){
			for(j=i;j<=n;j++){
				b[a[j]]=max(0LL,b[a[j]]-1LL);
			}
		}
		bj[a[i]]=1;
	}
	for(i=1;i<=m;i++)cout<<b[i]<<' ';
	return 0;
}
