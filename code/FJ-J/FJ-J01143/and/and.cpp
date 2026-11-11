#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int y(long long a,long long b){
	int x[33],y[33],z[33],i=0,j=0;
	while(a!=0){
		i++; 
		x[i]=a%2;
		a/=2;
	}
	while(b!=0){
		j++;
		y[j]=b%2;
		b/=2;
	}
	long long sum=0;
	for(int k=1;k<=min(i,j);k++){
		if(x[k]==1&&y[k]==1){
			z[k]=1;
			sum+=pow(2,k-1);
		}else{
			z[k]=0;
		}
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","d",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int x=y(a[n],a[n-1]);
	for(int i=1;i<m-1;i++){
		x=y(x,a[n-1-i]);
	}
	cout<<x;
	return 0;
} 
