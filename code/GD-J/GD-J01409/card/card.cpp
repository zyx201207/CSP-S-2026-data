#include<bits/stdc++.h>
using namespace std;

#define int long long
int n,m,a[500005],sum[300005]={0},b[500005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int k=n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool p=0;
			for(int y=1;y<=k;y++){
				if(b[y]==a[j]){
					for(int h=y;h<=k;h++){
						b[h]=0;
					}
					b[y]=a[j];
					k=y;
					p=1;
					
					break;
				}
			}
			if(p==0){
				k++;
				b[k]=a[j];
			}
		}
		for(int i=1;i<=k;i++){
			sum[b[i]]++;
		}
		k=n;
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
	return 0;
}

