#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,c,d;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			a[j]=b[j];
		}
		d=0;
		for(int j=1;j<=n;j++){
			c=0;
			for(int l=j;l<=n;l++){
				if(a[l]==a[j]){
					c++;
				}
				if(c>=1){
					a[l]=-1;
				}
			}
			for(int l=1;l<=n;l++){
				if(a[l]==j){
					d++;
				}
			}
		}
		cout<<d<<" ";
	}
	return 0;
}
