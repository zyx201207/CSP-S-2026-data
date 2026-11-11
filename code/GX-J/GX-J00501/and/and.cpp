#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long a[N],b[N];
long long ma[N];
int two(int n){
	int a=0,aa=10;
	while(n>0){
		a=n%2*aa+a;
		n/=2;
		aa*=10;
	}
	return a;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=two(a[i]);
	}
	int max1=0;
	int n1,n2;
	for(int i=0;i<n;i++){
		n1=b[i];
		for(int j=i+1;j<n;j++){
			n2=b[j];
			int bbb=n1&n2;
			max1=max(max1,bbb);
			ma[bbb]++;
		}
	}
	for(int i=max1;i>=0;i--){
		if(ma[i]==m){
			cout<<i;
			return 0;
		}
	}
	return 0;
}
