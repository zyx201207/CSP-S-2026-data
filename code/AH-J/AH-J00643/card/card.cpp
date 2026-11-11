#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[500005],cnt[300005];
vector<LL> v;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	for(LL tg=0;tg<n;tg++){
		v.clear();
		for(LL i=tg+1;i<=n;i++){
			LL pos=-1,len=v.size();
			for(LL j=0;j<len;j++){
				if(v[j]==a[i]){
					pos=j;
					break;
				}
			}
			if(pos!=-1){
				while(1){
					if(v.back()==a[i]){
						v.pop_back();
						break;
					}
					else v.pop_back();
				}
				v.push_back(a[i]);
			}
			else v.push_back(a[i]);
		}
		LL len=v.size();
		for(LL i=0;i<len;i++){
			cnt[v[i]]++;
		}
	}
	for(LL i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
