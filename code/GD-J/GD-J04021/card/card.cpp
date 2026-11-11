#include<bits/stdc++.h>
using namespace std;
int n,m,ans[300005],d[500005];
int a[500005],o = 0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) {
		scanf("%d",&d[i]);
	}
	for(int i=0;i<n;i++){
		
		for(int j=0;j<n;j++) a[j]=0;
		o=0;
		
		for(int j=i;j<n;j++){
			//cout << -2;
			int x = d[j];
			for(int z = 0;z<o;z++){
				if(x!=a[z]) continue;
				for(int k = z;k<o;k++){
					a[k]=0;
				}
				o = z;
			}
			a[o] = x;
			o++;
		}
		for(int j=0;j<o;j++){
			ans[a[j]]++;
			//cout <<a[j];
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
