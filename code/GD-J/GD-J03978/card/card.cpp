#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],cnt,ans[300005];
int i,j,k;
bool p[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		memset(p,0,sizeof(p));
		for(j=i;j<=n;j++){
			if(p[a[j]]==0){
				ans[a[j]]++;
				p[a[j]]=1;
			}
		}
	}
	for(i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
