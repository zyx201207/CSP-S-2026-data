#include<bits/stdc++.h>
using namespace std;
long long n,m,a[101],maxx=0;
int main(){
	freopen("and.in","r"stdin);
	freopen("and.out","w"stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(i%2>a[i]) maxx=i;
	}
	cout<<maxx;
	return 0;
}
