#include<cstdio>
#include<cmath>
int n; 
long long ans;
struct letter
{
	int a;
	char c;
}s[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	  scanf("%d %c",&s[i].a,&s[i].c);
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		if(l==r) break; 
		if(s[l].c==s[r].c) {
			if(s[l].a<=s[r].a) {
				s[r].a-=s[l].a;
				s[l].a=0;
			}
			else {
				s[l].a-=s[r].a;
				s[r].a=0;
			}
		}
		else {
			if(s[l].a<=s[r].a) {
				s[r].a-=s[l].a;
				ans+=(long long)(s[l].a);
				s[l].a=0;
			}
			else {
				s[l].a-=s[r].a;
				ans+=(long long)(s[r].a);
				s[r].a=0;
			}
		}
		if(s[l].a==0) l++;
		if(s[r].a==0) r--;
	}
	printf("%lld",ans);
	return 0;
} 
