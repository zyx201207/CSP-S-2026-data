#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],cnt,ans,i,j;
bool b[200005];
int main(void) {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i) scanf("%d",&a[i]);
	for(i=29;i>=0;--i) {
		for(j=cnt=0;j<n;++j)
			if(!b[j]&&(a[j]&(1<<i))) ++cnt;
		if(cnt>=m) {
			for(j=0;j<n;++j)
				if(!(!b[j]&&(a[j]&(1<<i)))) b[j]=true;
			ans|=(1<<i);
		}
	}
	printf("%d",ans);
	return 0;
}
