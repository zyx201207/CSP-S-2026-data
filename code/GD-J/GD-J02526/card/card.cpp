#include<bits/stdc++.h>
using namespace std;
long long n,m,d[5000005],a[500005],b[300005],c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int o=1;
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0)b[a[j]]=o,d[o]=a[j],o++;
			else{
				for(int k=b[a[j]]+1;k<o;k++){
					b[d[k]]=0;
					d[k]=0;
				}
				o=b[a[j]]+1;
			}
		}
		for(int j=1;j<=o;j++){
			c[d[j]]++;	
		}
		for(int j=1;j<=m;j++)d[j]=0,b[j]=0;
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	return 0;
}
