#include<bits/stdc++.h>
using namespace std;
int n,m,x,ans;
vector<int>v;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>x,v.push_back(x);
	for(int i=29;i>=0&&(int)v.size()>=m;i--){
		sort(v.begin(),v.end(),[&](int x,int y){return x>y;});
		bool flg=1;
		for(int j=0;j<m&&flg;j++)
			if(~v[j]&(1<<i)) flg=0;
		if(flg){
			ans+=1<<i;
			while(~v.back()&(1<<i)) v.pop_back();
		}
		for(int j=0;j<(int)v.size();j++) v[j]&=(1<<i)-1;
	}
	cout<<ans;
	return 0;
}

