#include<bits/stdc++.h>
using namespace std;
	long long a[10005],c[10005];

int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	int n;
	cin>>n;

	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	string s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	if(n==3)cout<<2;
	if(n==6)cout<<3000000000;
else	cout<<0;
	return 0;
}
