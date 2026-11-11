#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,inf=0x3f3f3f3f;
char g[N];
int n,l,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	for (int i=1;i<=n;i++){//a*n
		int x;
		char y;
		cin >>x >>y;
		for (int i=l+1;i<=l+x;i++) g[i]=y;
		l+=x;
	}
	for (int i=1;i<=l/2;i++){//a*n/2
		int j=l+1-i;
		if(g[i]!=g[j]) ans++; 
		//cout <<i <<" " <<j <<endl;
	}
	cout <<ans;
	return 0;
}
