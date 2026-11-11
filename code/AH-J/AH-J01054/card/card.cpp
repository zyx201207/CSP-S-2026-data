#include <bits/stdc++.h>
using namespace std;
int a[500010];
int cnt[300010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k=1;
		int b[500010]={0};
		int c[3][500010]={0};
		for(int j=i;j<=n;j++){
			b[k]=a[j];
			if(c[1][b[k]]==1){
				int l=c[2][b[k]];
				for(int i=c[2][b[k]];i<k;i++){
					c[1][b[i]]=0;
					c[2][b[i]]=0;
				}
				k=l;
				c[1][b[k]]=1;
				c[2][b[k]]=k;
			}else{
				c[1][b[k]]=1;
				c[2][b[k]]=k;
			}
			k++;
		}
		k--;
		for(int i=1;i<=k;i++){
			cnt[b[k]]++;
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[m]<<" ";
	}
	return 0;
}
