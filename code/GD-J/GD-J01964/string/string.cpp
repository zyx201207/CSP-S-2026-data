#include<bits/stdc++.h>
using namespace std;
long long n,l,cnt;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=0,x;i<n;i++){
		char c;
		scanf("%lld %c",&x,&c);
		for(int j=0;j<x;j++){
			a+=c;
		}
		l+=x;
	}
	for(int i=0;i<l/2;i++){
		if(a[i]!=a[l-i-1]){
			cnt++;
		}
	}
	printf("%lld",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
