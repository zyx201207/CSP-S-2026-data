#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500100],b[500100][500100];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[j][i]=a[j]-a[i];
		}
	}
	long long ans=m,sum=0,k=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]<0) break;
			ans-=b[i][j];
			if(ans<0) break;
			k++;
		}
		sum=max(sum,k);
		k=0;
		ans=m;
	} 
	cout<<sum;
	
	return 0;
} 
