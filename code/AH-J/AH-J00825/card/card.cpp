#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[500000+10],cnt[500000+10];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    LL l=1,r=n;
    for(int k=1;k<=n;k++){
		LL pre[500000+10]={0};
		vector<LL> v;
		for(int i=l;i<=r;i++){
			if(pre[a[i]]){
				while(!v.empty() && v.back()!=a[i]) v.pop_back();
				for(int j=pre[a[i]]+1;j<i;j++) pre[a[j]]=0;
			}
			else v.push_back(a[i]);
			pre[a[i]]=i;
		}
		l++;
		for(int i=0;i<LL(v.size());i++) cnt[v[i]]++;
	}
	for(int i=1;i<=m;i++) printf("%lld ",cnt[i]);
    return 0;
}
