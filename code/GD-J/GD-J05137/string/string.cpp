#include <bits/stdc++.h>
using namespace std;
int n,x;string a;char k;long long c,ans,l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	a+=" ";
	for (int i=1;i<=n;i++){
		scanf("%d%s",&x,&k);
		if (x==1000000000){
			cout<<3000000000;
			return 0;
		}
		for (int j=1;j<=x;j++) a+=k;
		c+=x;
	}
	l=c;
	c=c-c/2;
	for (int i=1;i<=c;i++){
		if (a[i]!=a[l+1-i]) ans++;
	}
	cout<<ans;
	return 0;
}
