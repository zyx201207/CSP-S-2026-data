#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+5;
long long a[N],n,m,l,k;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	l=a[n/2];
	k=a[n/2+1];
	int o=k&l;
	if(n%2==0){
		cout<<o;
	}else{
		cout<<a[n/2+1];
	}
	return 0;
}

