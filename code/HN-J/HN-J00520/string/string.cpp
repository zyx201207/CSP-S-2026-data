#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	bool flag=true;//,lagf=true;
	for (ll i=1;i<=n;i++) {
		cin>>a[i]>>c[i];
		if (a[i]>1) flag=false;
		//if (c[i]!=c[i-1]&&i!=1) lagf=false;
	}
	//if ()
	if (n==1){
		puts("0");
		return 0;
	}
	if (n%2==0) {
		cout<<(n >> 1);
		return 0; 	
	}
	if (flag){
		cout<<((n-1) >> 1);
	}
	return 0;
}//520-1314 
