#include <iostream>
#include <string>
using namespace std;

long long n,m,a[201200];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=n-1;i>=1;i--){
		for (int j=1;j<=i;j++){
			if (a[j]>a[j+1]){
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for (long long  i=n-1;i>=0;i++){
		a[i]=a[i+1]&sa[i];
		if (i==m)
			cout<<a[i];
	}
	return 0;
}
