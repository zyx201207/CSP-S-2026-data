#include<bits/stdc++.h>
using namespace std;
long long n,m,x;
int a[500005],d[500005],b[300004];
int main(){
	preopen("card.in","r",stdin);
	preopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int y=0;
	for(int i=1;i<=n;i++){
		y++;
		for(int j=y;j<=n;j++){
			d[j]=a[j];
			for(int z=y;z<j;z++){
				if(d[z]==d[j]){
					for(int x=z;x<j;x++){
						d[x]=0;
					}
				}
			}
		}
		for(int c=y;c<=n;c++){
			if(d[c]>0) b[d[c]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
