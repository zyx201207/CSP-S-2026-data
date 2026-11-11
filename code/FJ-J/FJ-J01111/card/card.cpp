#include<bits/stdc++.h>
using namespace std;
int a[500009];
int b[300009];
int c[300009];
int d[300009];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int h=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				for(int k=h;k>=0;k--){
					if(c[k]!=a[j]){
						c[k]=0;
						h--;
					}
				}
			}else{
				b[a[j]]=1;
				h++;
				c[h]=a[j];
			}
		}
		for(int i=1;i<=h;i++){
			d[c[i]]++;
		}
		for(int i=1;i<=m;i++){
			b[i]=0;
			c[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}

