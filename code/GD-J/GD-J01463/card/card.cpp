#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],bj[300005],ans[300005],mn[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		ll cnt=1;
		memset(bj,0,sizeof(bj));
		for(int j=i;j<=n;j++){
			if(bj[a[j]]==0){
				mn[cnt]=a[j];bj[a[j]]=1;cnt++;
			}
			else {
				while(cnt>=1&&mn[cnt]!=a[j]){
					bj[mn[cnt]]=0;
					mn[cnt]=0;
					cnt--;
				}cnt++;
			}
		}
		for(int k=1;k<=cnt;k++){
			ans[mn[k]]++;
			mn[k]=0;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
		
	return 0;
}
