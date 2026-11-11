#include<bits/stdc++.h>
using namespace std;
long long n,a,i=0,cnt=0,m=0,f=1;
const long long N=900000005;
char s[N],s1[N];
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string,out","w",stdout);
	scanf("%lld",&n); 
	while(n--){
		scanf("%lld",&a);
		cin >>c;
		for(i;i<m+a;i++){
			s[i]=c;
		}
		m+=a;
	}
	for(long long i=0;i<m;i++){
		s1[i]=s[m-i-1];
		if(s1[i]!=s[i]){
			f=0;
		}
	}
	for(long long i=0;i<m;i++){
		if(s[i]!=s1[i]){
			cnt++;
		}
	}
	printf("%lld",cnt/2);
	return 0;
}
