#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005],b[1000005],c[1000005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cout.tie();
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==m){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			b[++sum]=a[j];
			for(int k=1;k<=sum;k++)
				if(b[k]==b[sum]){
					for(int l=k+1;l<=sum;l++)b[l]=0;
					break;
				}
		}
		for(int j=1;j<=sum;j++)c[b[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	return 0;
}
