#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	bool f=1;
	for(int i=1;i<=n;i++){
		char t;
		cin>>a[i]>>s[i];
		if(i) t=s[i];
		else{
			if(s[i]!=t) f=0;
		}
	}
	if(f){
		cout<<0;
		return 0;
	}
	bool f1=1;
	for(int i=1;i<=n/2+1;i++){
		if(a[i]!=a[n-i+1]&&s[i]!=s[n-i+1]){
			f1=0;
		}
	}
	if(f1) cout<<0;
	return 0;
}
