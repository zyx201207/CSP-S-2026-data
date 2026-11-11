#include<bits/stdc++.h> 
using namespace std;
long long n,m;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin >> n >> m;
	long long a[n+5];
	sort(a,a+n+2);
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	cout << a[0];
	return 0;
}
