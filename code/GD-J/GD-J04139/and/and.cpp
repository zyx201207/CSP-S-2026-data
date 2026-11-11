#include<bits/stdc++.h> 
using namespace std;
int a[200005];
int b[200005];
int nb[200005];
int sum=INT_MAX;
int nmax=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		while(a[i]!=0){
			b[i]=a[i]%2+b[i]*10;
		}
	}
	for(int j=n;j>=1;j--){
			int k=1;
			nb[k]=b[j];
			k++;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=m+i;j++){
			sum=sum&nb[j];
			if(sum>=nmax){
				nmax=sum;
			}
		}
	}
	cout<<nmax;
	return 0;
}
