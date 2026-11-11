#include<bits/stdc++.h>
using namespace std;
int n,m,c[500005],cnt;
int main(){
	map<int,int> mp;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		scanf("%d",&c[i]);
		
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			mp.clear();
			cnt=0;
			for(int k=j;k<=n;++k)
				if(c[k]==i)
					cnt++;
			for(int k=j;k<=n;++k){
				if(mp.count(c[k])==1&&mp[c[k]]!=0){
					for(int o=mp[c[k]];o<=k;++o){
						if(mp.count(c[o])==1)
							mp[c[o]]=0;
						if(c[o]==i)
							cnt--;
					}
				}
				mp[c[k]]=k;
			}
		}
		
		printf("%d ",cnt);
	}
	return 0;
}
