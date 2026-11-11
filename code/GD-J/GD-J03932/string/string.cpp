#include<bits/stdc++.h>
using namespace std;
int n,a[200010],top1,top2;
long long ans,p,top;
char c[200010],s[900000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d %c",&a[i],&c[i]);
		for(int j = 1;j <= a[i];j++){
			s[++top] += c[i];
		}
		ans += a[i];
	}
	for(int i = 1,j = ans;i != j;i++,j--){
		if(s[i] != s[j])
			p++;
	}
	printf("%d",p);
}
