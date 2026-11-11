#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
const int M=3e5+10;
int a[N];
int position[N];
vector<int> cur;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	bool flag_A=1;
	set<int>se;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		se.insert(a[i]);
		position[a[i]]=i;
		if(!(a[i]>=a[i-1]))flag_A=0;
	}
	for(auto it:se){
		cur.push_back(it);
	}
	if(flag_A){
		for(int i=1;i<=m;i++)cout<<position[cur[i-1]]<<" ";
	}
	return 0;
}