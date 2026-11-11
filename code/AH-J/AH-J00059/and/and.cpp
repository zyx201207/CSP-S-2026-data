#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[i]<a[j]){
				int e=a[i];
				a[i]=a[j];
				a[j]=e;
			}
		}
	}
	int b=a[1];
	for(int i=2;i<=m;i++){
		b=b&&a[i];
	}
	cout<<b;
	return 0;
}
