#include<bits/stdc++.h>
using namespace std;
int n,m,y,p=1;
int a[500010],b[300010];
bool c[300010];
int z[300010];
int x[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	y=m;
	while(y!=1){
		if(c[x[p]]!=0){
			if(z[x[p]]!=0){
				c[p]=0;
				for(int i=z[x[p]+1];i<=n;i++){
					x[p]=0;
				}
				p=x[p]-1;
				z[x[p]]=0;
				y--;
				b[x[p]]++;
			}
			else{
				p++;
				z[x[p]]=p;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i];
	}
	return 0;
}
