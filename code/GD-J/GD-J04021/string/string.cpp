#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char e[200005];
bool c1(char d){
	for(int i=0;i<n;i++){
		if(e[i]!=d) return false;
	} 
	return true;
}
bool c2(){
	for(int i=0;i<n/2;i++){
		if(e[i]!=e[n-1-i]||a[i]!=a[n-1-i]) return false;
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d %c",&a[i],&e[i]);
	char d = e[0];
	if(c1(d)){
		printf("0");
		return 0;
	}
	if(c2()){
		printf("0");
		return 0;
	}
	long long ans = 0;
	for(int i=0;i<n;i++){
		ans += 1LL*a[i];
	}
	long long sum = ans/2;
	printf("%lld",sum);
	return 0;
}
