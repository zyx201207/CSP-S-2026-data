#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,a[N],ans,f=-1;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int j=n; j>=m; j--) {
		ans=a[j];
		for(int i=j-1; i>j-m; i--) {
			ans=ans&a[i];
		}
		f=max(f,ans);
	}
	printf("%d",f);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//Trick||Treat!
