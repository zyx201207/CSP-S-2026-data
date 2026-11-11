#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],cnt[300010];
vector<int>v;
void mn(int id){
	v.clear();
	for(int i=id;i<=n;i++){
		for(int j=(int)v.size()-1;j>=0;j--)
			if(v[j]==a[i]){
				for(int k=v.size()-j;k>=1;k--) v.pop_back();
				break;
			}
		v.push_back(a[i]);
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		mn(i);
		for(int x:v) cnt[x]++;
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}
