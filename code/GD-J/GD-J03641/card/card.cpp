#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],l=1,r=1,b[300001],ans[500001],re;
int find(int x){
	for(int o=0;o<n;o++)
		if(a[o]==x)
			return o;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(ans,0,sizeof(ans));
	cin>>n>>m;
	for(r=1;r<=n;r++)cin>>a[r];
	for(int j=1;j<=n;j++){
		memset(b,0,sizeof(b));
		for(l=j;l<=n;l++){
			if(b[a[l]]==1){
				re=find(a[l]);
				for(int i=re;i<l;i++)
					b[a[i]]=0;
				b[a[l]]=1;
				continue;
			}
			b[a[l]]=1;
		}
		for(int k=1;k<=m;k++){
			if(b[k]==1)
				ans[k]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
