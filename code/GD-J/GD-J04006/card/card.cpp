#include <bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
const long long M=3e5+10;
long long n,m,a[N],b[N],c[M],x=1,k=0,p;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(x<=n){
		for(int i=x;i<=n;i++){
			p=0;
			for(int j=1;j<=k;j++){
				if(b[j]==a[i]){
					p=j;
					break;
				}
			}
			if(p==0){
				k++;
				b[k]=a[i];
			}else{
				for(int l=p;l<=k;l++){
					b[l]=0;
				}
				b[p]=a[i];
				k=p;
			}
		}
		for(int h=1;h<=k;h++){
			c[b[h]]++;
		}
		for(int y=1;y<=m;y++){
			b[y]=0;
		}
		k=0;
		x++;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	return 0;
}
