#include <bits/stdc++.h>
using namespace std;
int a[500010],b[500010],c[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int y=1;
		for(int j=i;j<=n;j++){
			bool q=0;
			int xia;
			if(sizeof(b)>1){
				for(int m=1;m<=y;m++){
					if(b[m]==a[j]){
						xia=m;
						q=1;
						break;
					}
				}
			}else if(a[j]==b[1]) q=1;
			if(q){
				int z=y;
				for(int m=xia;m<=z;m++){
					b[m]=0;
					y--;
				}
			}
			y++,b[y]=a[j];
		}
		for(int j=1;j<=y;j++){
			c[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
