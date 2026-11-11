#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[200005][35],m,s[3];
ll ai,ans;
bool can[200005];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&ai);
		for(int j=0;j<=29;j++) {
			a[i][j]=ai&1;
			ai>>=1;
		}
		can[i]=true;
	}
	for(int j=29;j>=0;j--) {
		s[0]=s[1]=0;
		for(int i=1;i<=n;i++) {
			if(!can[i]) continue;
			s[a[i][j]]++;
		}
		ans<<=1;
		if(s[1]>=m) {
			for(int i=1;i<=n;i++) {
				if(a[i][j]==0) can[i]=false;
			}
			ans|=1;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
