#include<bits/stdc++.h>
using namespace std;
long long n , s = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int a[n+5];
	string b[n+5];
	for(int i = 0 ; i < n ; i++ ){
		cin>>a[i]>>b[i];
	}
	for(int i = 0 ; i < n/2 ; i++ ){
		if(b[i] != b[n-i-1]) s+=max(a[i],a[n-i-1]);
	}
	cout<<s;
	return 0;
}
