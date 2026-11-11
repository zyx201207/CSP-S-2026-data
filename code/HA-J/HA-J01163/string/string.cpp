#include <bits/stdc++.h>
long long n,a[100000001];
char b[100000001];
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	if(n<=1){
		cout<<"0";
	}
	else if(n=2){
		if(a[1]>a[2])
			cout<<a[2];
		else
			cout<<a[1];
	}
	return 0;
}
