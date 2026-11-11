#include<bits/stdc++.h>
using namespace std;
long long n,x,f;
long long a[150];
char k;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>x>>k;
		f+=x;
	}
	if (n==1){
		cout<<0;
		return 0;
	}
	cout<<f;
	return 0;
}
