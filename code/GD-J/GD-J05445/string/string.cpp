#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[10005],sum=0;
	string c,s,s2;
	int len=0;
	cin>>n;
	if(n<2) cout<<0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		if(c[i]==c[i-1]) cout<<0;
		else if(n<=2 && a[i]==a[i-1]) cout<<0;
	} 
	return 0;
}
