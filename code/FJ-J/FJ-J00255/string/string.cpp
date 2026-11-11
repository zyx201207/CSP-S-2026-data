#include <bits/stdc++.h>
using namespace std;
long long n,ma=1,ans;
char c[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);///////////
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char j;
		cin>>a>>j;
		long long k=ma+a;
		for(;ma<k;ma++) c[ma]=j;
	}
	for(int i=1,j=ma-1;i<=j;i++,j--){
		if(c[i]!=c[j]) ans+=1;
	}
	cout<<ans;
	return 0;
}