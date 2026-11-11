#include <bits/stdc++.h>
using namespace std;
int n,m,a[500001],ans[300001],p[300002],l[300002],o,u,len,flag;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)p[j]=0,l[j]=0;
		o=0;
		for(int j=i;j<=n;j++){
			if(p[a[j]]==0)l[++o]=a[j],p[a[j]]=o;
			else{
				for(int x=o;x>p[a[j]];x--)p[l[x]]=0;
				o=p[a[j]];
			}
		}
		for(int j=1;j<=m;j++)if(p[j]!=0)ans[j]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
