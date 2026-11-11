#include <bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],c[300010];
bool z;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int last=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			z=0;
			for(int k=1;k<=last;k++){
				if(b[k]==a[j]){
					last=k;
					z=1;
					break;
				}
			}
			if(z==0){
				last++;
				b[last]=a[j];
			}
		}
		for(int k=1;k<=last;k++){
			c[b[k]]++;
		}
		last=0;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
