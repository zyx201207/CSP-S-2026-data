#include<bits/stdc++.h>
using namespace std;
long long n,x,a,s;
char asd;
string s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		a+=x;
		cin>>asd;
		for(int j=1;j<=x;j++){
			s1+=asd;
		}
	}
	for(int i=0;i<a/2;i++){
		if(s1[i]==s1[a-i-1]) continue;
		else{
			s++;
		}
	}
	printf("%lld",s);
	return 0;
} 
