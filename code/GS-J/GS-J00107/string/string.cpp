#include<bits/stdc++.h>
using namespace std;
int a[200010];
char s[200010];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	scanf("%d",&n);

	for(int i=1; i<=n; ++i) {
		int x;
		char S;
		cin>>x>>S;
		a[i]+=x;
		s[i]=S;
	}
	bool flag=1;
	for(int i=1; i<=n; ++i) {
		if(s[i]!=s[i+1]) {
			flag=0;
		}
	}
	if(flag) printf("0");
	int l=1,r=n;
	while(l<=r) {
		if(a[l]==a[r]&&s[l]==s[r]) {
			l++,r--;
		} else if(s[l]!=s[r]) {
			if(a[l]>a[r]) {
				ans+=a[l]-a[r];
				s[l]=s[r];
			}

			else if(a[l]<a[r]) {
				ans+=a[r]-a[l];
				s[r]=s[l];
			} else {
				ans+=a[r];
				s[l]=s[r];
			}
		}
	}
	printf("%d",ans);
	return 0;
}
