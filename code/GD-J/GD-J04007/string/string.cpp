#include <bits/stdc++.h>
using namespace std;
char b[114514];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	bool ch=true;
	char c;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a>>c;
		b[i]=c;
		if(i>=2 && b[i]!=b[i-1]){
			ch=false;
		} 
	}
	if(ch){
		cout<<"0";
	}
	return 0;
} 
