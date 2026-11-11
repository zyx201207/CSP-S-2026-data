#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],cnt[N],ans[N],t[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=n;i;--i){
		if(!t[a[i]])t[a[i]]=i,cnt[i]=1;
		else cnt[t[a[i]]]++;
	}
	for(int i=1;i<=n;++i){
		if(t[a[i]]!=i)continue;
		ans[a[i]]+=cnt[i];
		cnt[t[a[i+1]]]+=cnt[i];
	}
	for(int i=1;i<=m;++i)
		printf("%d ",ans[i]);
	return 0;
}
