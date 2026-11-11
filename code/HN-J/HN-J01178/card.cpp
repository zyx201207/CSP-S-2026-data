#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009],num,b[500009],i,j;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	for(i=1;i<=n;i++){
	if(n==m){
		cout<<i<<' ';
	}
}
for(int g=1;g<=n;g++){
	for(i=n;i<=1;i++){
		for(j=1;j<=n;j++){
			while(n!=m){
				if(a[i]==a[j]){
					for(int k=i;k<=j-1;j++){
						a[k]=0;
					}
				}
			}
		}
	}
	b[g]+=a[i];
	if(a[i]==a[j]){
		b[i]=b[i]+b[j];
	}
	cout<<b[g]<<' ';
}
	return 0;
}

