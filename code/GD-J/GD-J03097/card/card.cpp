#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],x,b[300005],z[300005]={0},ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		x=i;
		for(int j=i;j<=n;j++){
			if(z[a[x]]==0){
				z[a[x]]=1;
				b[a[x]]=j;
			}
			else {
				for(int k=b[a[x]]+1;k<j;k++){
					if(b[a[x]]<b[a[k]]){
						z[a[k]]=0;
						b[a[k]]=0;
					}
				}
			}
			x++;
		}
		for(int j=1;j<=m;j++){
			if(z[j]!=0){
				ans[j]++;
				z[j]=0;
				b[j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
} 
