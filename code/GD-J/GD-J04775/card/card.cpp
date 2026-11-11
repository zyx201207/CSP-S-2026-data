#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],cnt[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		cnt[a[i]]++;
		for(int j=n;j>=i;j--){
			if(cnt[a[j]]<=1){
				ans[a[j]]++;
			}
			else{
				ans[a[j]]++;
				break;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
