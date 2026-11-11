#include <bits/stdc++.h>
using namespace std;

string s;
int n;
int sum;
long long a[200010];
char t,c;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%c%c",&a[i],&c,&t);
		s.insert(0,a[i],t);
	}
	string s2=s;
	int len=s.size();
	
	for(int i=0;i<len;i++)
		s2[i]=s[len-1-i];
	
	for(int i=0;i<=len/2;i++){
		if(s[i]!=s2[i])
			sum++;
	}
	printf("%d",sum);
}
