#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdin);
	int n;
	cin>>n;
	int a[n];
	char c[n];
	string s="";
	int o=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		o+=a[i];
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	int p=0;
	for(int i=0;i<o/2+1;i++){
		if(s[i]!=s[o-i-1]){
			p++;
		}
	}
	cout<<p;
}
