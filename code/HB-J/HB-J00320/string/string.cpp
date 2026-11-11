#include<bits/stdc++.h>
using namespace std;
long long n,x[20005],y[20005],a;
int main(){
	freopen("string.in",r,stdin);
	freopen("string.out",w,stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	if(n==1) cout<<0;
	for(int i=2;i<=n;i++){
		if(y[i]==y[i-1]) a++;
	}
	if(a==n-1) cout<<0;
	else cout<<n/2*x[1];
	return 0;
}
