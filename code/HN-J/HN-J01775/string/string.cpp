#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n; cin>>n;
	int a[n];
	char c[n],s[n];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s[j]=c[j];
		}
	}
	for(int i=1;i<=n;i++){
		cout<<s[i];
	}
	return 0;
}
