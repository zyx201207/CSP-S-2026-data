#include<bits/stdc++.h>
using namespace std;
int a[500005],f[300005],ans[300005];
vector<int> v;
int main(){
	int n,m;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		v.clear();
		memset(f,0,sizeof f);
		for(int j=i;j<=n;j++){
			if(f[a[j]]>0){
				while(v[v.size()-1]!=a[j]) f[v[v.size()-1]]--,v.pop_back();
				v.pop_back();
				f[a[j]]--;
			}
			v.push_back(a[j]);
			f[a[j]]++;
		}
		for(int j=0;j<v.size();j++){
			ans[v[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
