#include<stdio.h>
int n,a,i;
int sum,ans,len;
char c[2],s[100000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d %s",&a,c);
		for(int j=1;j<=a;++j)s[++len]=*c;
	}
	for(i=1;i*2<=len;++i){
		if(s[i]!=s[len-i+1])++ans;
	}
	printf("%d",ans);
	return 0;
}
