#include <bits/stdc++.h>
using namespace std;
const int N=200005;
struct node {
	long long num;
	char a;
} s[N];
long long n,l,r,ans=0;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&s[i].num);
		scanf(" %c",&s[i].a);
	}
	l=1;
	r=n;
	while(l<r) {
		if(s[l].a != s[r].a) {
			if(s[l].num == s[r].num) {
				ans+=s[l].num;
				l++;
				r--;
			} else if(s[l].num > s[r].num) {
				ans+=s[r].num;
				s[l].num-=s[r].num;
				r--;
			} else {
				ans+=s[l].num;
				s[r].num-=s[l].num;
				l++;
			}
		} else {
			if(s[l].num == s[r].num) {
				l++;
				r--;
			} else if(s[l].num > s[r].num) {
				s[l].num-=s[r].num;
				r--;
			} else {
				s[r].num-=s[l].num;
				l++;
			}
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
