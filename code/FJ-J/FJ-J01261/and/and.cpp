#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,at,sum;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		int a;
		cin>>a;
		sum=max(at,a);
		at=a;
	}
	cout<<sum;
	return 0;
}
