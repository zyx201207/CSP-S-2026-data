#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[500010],b[300010],ans[300010],sum[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)b[a[j]]++;
		for(int j=i;j<=n;j++){
			if(b[a[j]]>1){
				int k=j;
				sum[a[k]]=1;
				for(;j<=n&&b[a[k]]>0;j++){
					b[a[j]]--;
				}
			}
			sum[a[j]]=1;
			b[a[j]]--;
		}
		for(int j=1;j<=m;j++){
			ans[j]+=sum[j],sum[j]=0,b[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
