#include<bits/stdc++.h>
using namespace std;
char s[16000000];
long long a;
int huiwen(){

	long long c=0;
	for(int i=0;i<=a/2;i++){
		if(s[i]!=s[a-i]){
			c++;
		}
	}
	return c;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long w;
		char y1;
		scanf("%lld %c",&w,&y1);
		a+=w;
		for(long long j=1;j<=w;j++){
			s[i]=y1;
		}
	}
	printf("%d",huiwen());
	return 0;
}

