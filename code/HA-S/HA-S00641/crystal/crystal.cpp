#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt;
long long a[10000000];
long long b[10000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		b[i]=a[i]-a[i+1];
	}
	b[n]=0; 
	for(int i=1;i<=n;i++){
		m+=b[i];
		if(m<0){
			cout<<i;
			return 0;
		}
	}
	cout<<n;
	return 0;
} 
