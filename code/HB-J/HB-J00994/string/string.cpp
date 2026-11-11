#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[200500]={};
	char c[200500]={};
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	cout<<a[1];
	return 0;
}
