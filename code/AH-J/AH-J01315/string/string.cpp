#include<bits/stdc++.h>
using namespace std;
int n,c;
char s;
string s1;
long long a=0,b=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&c,&s);
		a+=c;
		for(int j=1;j<=c;j++){
			s1+=s;
		}
	}
	for(long long L=0,R=a-1;L<R;L++,R--){
		if(s1[L]!=s1[R]){
			++b;
		}
	}
	printf("%d",b);
	return 0;
}
