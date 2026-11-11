#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
int cnt[3*N],a[5*N];
set<int> v;
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(v.count(a[j]))v.clear();
			v.insert(a[j]);
		}
		for(auto j:v)cnt[j]++;
		v.clear();
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
