#include<bits/stdc++.h>
using namespace std;
int n,m,a[600000],b[600000],c[600000],d[500000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","W",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	int z=1;
	for(int i=1;i<=n;i++){
		int l=1;
		z=1;
		for(int j=i;j<=n;j++){
			bool f=1;
			l=1;
			while(1){
				if(c[l]==b[j]){
					c[l]=b[j];
					c[l+1]=0;
					z=l+1;
					f=0;
					break;
				}
				if(l>n) break;
				l++;
			}
			if(!f) continue;
			c[z]=b[j];
			z++;
		}
		l=1;
		while(c[l]!=0){
			d[c[l]]++;
			c[l]=0;
			l++;
		}
	}
	for(int i=1;i<=m;i++){
		if(a[n]==i){
			cout<<n<<' ';
			continue; 
		}
		cout<<d[i]<<' ';
	}
	return 0;
}
