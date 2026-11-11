#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005],v[500005],vi;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof v);
		vi=0;		
		for(int i2=i;i2<=n;i2++){
			int f=0;
			for(int j=1;j<=vi;j++){
				if(v[j]==a[i2]){
					vi=j;
					f=1;
					break;
				}				
			}
			if(f==0)v[++vi]=a[i2];
		}
		for(int j=1;j<=vi;j++){
			ans[v[j]]++;
		}
		
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
