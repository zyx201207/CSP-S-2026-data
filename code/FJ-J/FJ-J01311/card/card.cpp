#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],p[300005],ans[300005];
int main(){
 	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int x=1;x<=n;x++){
		memset(p,0,sizeof(p));
		for(int i=x;i<=n;i++){
			if(p[a[i]]){
				for(int j=p[a[i]]+1;j<=i;j++)
					if(p[a[j]]&&p[a[j]]!=p[a[i]])p[a[j]]=0;
			}
			else p[a[i]]=i;
		}
		for(int i=1;i<=m;i++)if(p[i])ans[i]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
 	return 0;
}
