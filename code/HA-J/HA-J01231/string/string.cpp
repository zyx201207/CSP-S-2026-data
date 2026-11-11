#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,x=0;
	char c,k;
	char s[10000005]={};
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		if(c==k)x=1;
		else x=0;
		k=c;
	}
	if(x=1)cout<<0;
	return 0;
}
