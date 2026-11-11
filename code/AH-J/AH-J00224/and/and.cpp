#include <bits/stdc++.h>
using namespace std;
int n,a[1000001],m,k=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	if (m==1){
		sort(a+1,a+n+1);
		cout << a[n-1];
		return 0;
	}
	else if (m==2){
		for (int i=1;i<n;i++){
			for (int j=i+1;j<=n;j++){
				k=max(k,a[i]&a[j]);
			}
		}
	}
	else if (m==n){
		k=a[1];
		for (int i=1;i<n;i++)
		{
			k&=a[i];
		}
	}
	cout << k;
	return 0;
}