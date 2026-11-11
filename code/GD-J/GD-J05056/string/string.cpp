#include<bits/stdc++.h>;
#define int long long
using namespace std;
int a[200000];
char c[200000];
signed main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	int n;
	cin>>n;
	int summ=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]<<c[i];
		summ+=a[i];
	}
	return 0;
} 
