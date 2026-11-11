#include <bits/stdc++.h>
using namespace std;
long long n,m,a[10000010],b[10000010],mi;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=a[i]&a[i+m];
		if(m<b[i]){
			m=b[i];
		}
	}
	cout<<m;
} 

