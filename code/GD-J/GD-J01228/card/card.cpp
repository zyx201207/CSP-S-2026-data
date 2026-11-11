#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],m,bl[300005],c[300005],sum[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(bl,0,sizeof(bl));
		memset(c,0,sizeof(c));
		for(int j=i;j<=n;j++){
			if(bl[a[j]]==0){
				bl[a[j]]=1,c[a[j]]=j;
			}
			else{
				for(int h=c[a[j]]+1;h<j;h++)
					bl[a[h]]=0;
				c[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++)
			if(bl[j]==1)
				sum[j]++;
	}
	for(int i=1;i<=m;i++)
		cout<<sum[i]<<' ';
	return 0;
}
