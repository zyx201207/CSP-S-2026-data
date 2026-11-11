//GZ-J00492 遵义市第十六中学 何世灏
#include <bits/stdc++.h>
using namespace std;

int n,m,a[500005],b[300005];
int c[500005],d[300005],k=0;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		k=0;
		for(int j=0;j<=m;j++){
			d[j]=c[j]=0;
		}
		for(int j=i;j<=n;j++){
			c[k]=a[j];
			k++;
			d[a[j]]++;
			if(d[a[j]]>1){
				bool st=0; 
				int u=0;
				for(int o=0;o<k;o++){
					if(c[o]==a[j]) st=1;
					if(st){
						u++;
						c[o]=0;
						d[a[j]]--;
					}
				}k-=u;
				c[k++]=a[j];
				d[a[j]]++;
			}
		}for(int j=0;j<k;j++){
			b[c[j]]++;
			cout<<c[j]<<' ';
		}cout<<"\n";
	}for(int i=1;i<=m;i++){
		printf("%d ",b[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

