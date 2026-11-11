#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],ans=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int sta[500005],tp=0;
		sta[1]=0;
		for(int o=i;o<=n;o++){
			for(int j=tp;j>=0;j--){
			    if(!j){
					sta[++tp]=a[o];
					break;
				}
			    if(sta[j]==a[o]){
					tp=j;
					break;
				}
		    }
		}
		for(int j=1;j<=tp;j++)
			b[sta[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<" ";
	return 0;
}
