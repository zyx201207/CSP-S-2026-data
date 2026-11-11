#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n,m,a[500005];
bool bbb[500005];
int res[500005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) {
		v.clear();
		memset(bbb,0,sizeof(bbb));
		for(int j=i;j<=n;++j) {
			if(!bbb[a[j]]) {
				v.push_back(a[j]);
				bbb[a[j]]=1;
			} else {
				int idx=find(v.begin(),v.end(),a[j])-v.begin();
				for(int k=idx;k<(int)v.size();++k)
				bbb[v[k]]=0;
				v.erase(v.begin()+idx,v.end());
				v.push_back(a[j]);
				bbb[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++)
		if(bbb[j])
		++res[j];
	}
	for(int i=1;i<=m;i++)
	cout<<res[i]<<
	" ";
	return 0;
}

