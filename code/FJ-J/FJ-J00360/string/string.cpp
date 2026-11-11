#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n+5]={};
	char s[n+5]={};
	for (int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	string S="";
	for (int i=1;i<=n;i++){
		S+=a[i]*s[i];
	}
	int cnt=0;
	for (int i=1;i<=n;i++){
		cnt+=a[i];
	}
	cout<<a[1];
	return 0;
}
