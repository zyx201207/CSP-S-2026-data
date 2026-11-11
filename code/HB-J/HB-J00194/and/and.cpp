#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans;
int a[N],b[N],tot;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	tot=n;
	for(int k=(1<<30);k>0;k>>=1){
		int sum=0;
		for(int i=1;i<=tot;++i)
			if(a[i]&k) b[++sum]=a[i];
		if(sum>=m){
			ans+=k;
			for(int i=1;i<=sum;++i) a[i]=b[i];
			tot=sum;
		}
		for(int i=1;i<=tot;++i) a[i]&=(~k);
	}
	printf("%d",ans);
	return 0;
}
