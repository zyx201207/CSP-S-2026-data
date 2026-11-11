#include<bits/stdc++.h>
using namespace std;
long long n,m,z;
long long a[300000],c[300000],b[300000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	z=n;
	while(n){
		for(int i=1;i<=n;i++){
			b[i]=0;
		}
		for(int i=z-n;i<z;i++){
			b[a[i]]++;
			if(b[a[i]]==2){
				for(int j=z-n+1;j<i+1;j++){
					b[a[j]]=0;
				}
				b[a[i]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			c[j]+=b[j];
		}
		n--;
	}
	for(int i=1;i<=m ;i++){
		cout<<c[i]<<' ';
	}
	return 0;
} 
