#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin>>n;
	int a[n+5]={0};
	int b[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]&a[i-1];
	}
	
	return 0;
}
