#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long int n;
	cin>>n;
	string a="0";
	if (n==1){
		cout <<"0";
		return 0;
	}
	long long int L=0;
	for (int i=1;i<=n;i++){
		long long int x;
		cin>>x;
		L+=x;
		string b;
		cin>>b;
		for (int j=1;j<=x;j++){
			a+=b;
		}
	}
	int ti=0;
	ti=L/2;
	long long int ans=0;
	for (int i=1;i<=ti;i++){
		if (a[i]!=a[L+1-i]){
			ans++;
		}
	}
	cout <<ans;
	return 0;
}
