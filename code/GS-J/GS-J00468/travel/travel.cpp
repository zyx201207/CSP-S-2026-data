#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>m>>n;
	int a[500005];
	int k;
	int z[500005];
	int b[500005];
	for(int i=1;i<=n;i++){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=1;j<=i-1;j++){
				if(a[i]!=a[i-1]&&a[i]!=0){
					z[i]=a[i];
				}else{
					z[j]=0;
				}
			}
		}
	for(int j=1;j<=n;j++){
		b[j]+=z[j];
		z[j]=0;
		}
		for(int j=1;j<=m;j++){
			
		}
	}
 	return 0;
}
