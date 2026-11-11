#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005],d[500005];
bool l[500005]={0};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int x=1,y=1;
	while(x<=n){
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(a[j]==a[i]){
					y=j;
					d[y]=a[i];
					break;
				}
				else{
					d[y]=a[i];
					y++;
					break;
				}
			}
		}
		for(int i=1;i<=y;i++){
				for(int j=1;j<=m;j++){
					if(d[i]==j){
						ans[i]++;
						break;
					}
				}
			}
		y=1;
		x++;
		}
		
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
