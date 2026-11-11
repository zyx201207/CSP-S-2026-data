#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	int a[500001];
	int b[500001];
	int c[500001]={0};
	int d[500001]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=i;
		int z=1;
		while(x<=n){
			if(d[a[x]]==0){
				b[z]=a[x];
				d[b[z]]++;
				z++;
			}else  if(d[a[x]]!=0){
				while(b[z]!=a[x]){
					z--;
				}
				z++;
			}
			cout<<z<<" ";
			x++;
		}
		for(int i=1;i<=z;i++){
			c[b[i]]++;
		}
		for(int i=1;i<=m;i++){
			d[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		if(c[i]>n){
			cout<<n<<" ";
		}else{
			cout<<c[i]<<" ";
		}
	}
	return 0;
}
