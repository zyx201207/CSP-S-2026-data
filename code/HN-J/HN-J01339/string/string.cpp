#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[n];
	string s[n];
	for(int i=0;i<=n-1;i++){
		cin>>a[i]>>s[i];
	}
	int o=0;
	string w=s[0];
	for(int i=1;i<=n-1;i++){
		if(w==s[i]){
			o++;
		}
	}
	if(o+1==n){
		cout<<0;
		return 0;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	cout<<n;
	return 0;
}
