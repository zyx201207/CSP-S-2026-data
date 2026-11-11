#include"bits/stdc++.h"
#define int long long
using namespace std;
int a[500005];
int s[500005];
vector<int>v;
map<int,int>mp,mp1;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=500&&m<=500){
	for(int z=1;z<=n;z++){
		v.clear();
		v.push_back(-1);
		mp1.clear();
		for(int i=z;i<=n;i++){
			if(mp1[a[i]]){
				int tmp=v.size();
				for(int j=mp1[a[i]];j<tmp;j++){
					mp1[v[j]]=0;
					v.pop_back();
				}
			}
			v.push_back(a[i]);
			mp1[a[i]]=v.size()-1;
		}
		for(int i=1;i<v.size();i++)
			mp[v[i]]++;
	}
	for(int i=1;i<=m;i++)
		printf("%lld ",mp[i]);
	}
	else{
		for(int i=1;i<=n;i++)
			mp[a[i]]++;
		for(int i=1;i<=m;i++){
			s[i]=s[i-1]+mp[i];
			printf("%lld ",s[i]);
		}
	}
	return 0;
}/*4 3
1 2 1 3*/
