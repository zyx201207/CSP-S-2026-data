#include<bits/stdc++.h>
using namespace std;
int n,m,k[500005],a[500005],x,st[300005],len;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&k[i]);
	for(int an=n;an>=1;an--){
		for(int i=1;i<=n;i++)a[i]=0;
		len=0;
		for(int i=n-an+1;i<=n;i++){
			x=k[i];
			int ans=-1;
			for(int j=1;j<=len;j++)
				if(a[j]==x){
					ans=j;
					break;
				}
			if(ans!=-1){
				for(int j=ans+1;j<=len;j++)a[j]=0;
				len=ans;
			}
			else{
				len++;
				a[len]=x;
			}
		}
		for(int i=1;i<=len;i++)st[a[i]]++;
	}
	for(int i=1;i<=m;i++)printf("%d ",st[i]);
	return 0;
}
