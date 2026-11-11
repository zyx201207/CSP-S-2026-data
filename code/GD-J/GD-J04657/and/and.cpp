#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int j=29;j>=0;--j){
		int cnt(0);
		for(int i=1;i<=n;++i)
			if((a[i]>>j)&1)++cnt;
		if(cnt>=m){
			ans|=(1<<j);
			int k(0);
			for(int i=1;i<=n;++i)
				if((a[i]>>j)&1)a[++k]=a[i];
			n=k;
		}
	}
	printf("%d",ans);
	return 0;
}
