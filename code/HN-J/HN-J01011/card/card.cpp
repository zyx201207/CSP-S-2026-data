#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],ans[N],lst[N];
vector<int> v;
unordered_map<int,int> mp;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		v.clear();mp.clear();
		//mp: 记录桌面上每张牌的数量 
		//v: 相当于桌面 
		//lst: 某张牌在桌面上第一次出现的位置 
		for(int j=1;j<=m;j++) lst[j]=-1;
		for(int j=i;j<=n;j++){
			if(mp[a[j]]>0){ //桌面上出现过a[j]了 
				int num=v.size();
				while(!v.empty()&&num>=lst[a[j]]){
					//把a[j]右边的包括a[j]都删掉 
					mp[v[num]]--;v.pop_back();
					//不要的删掉
					//同类牌出现的次数减少，总牌数减少
					num--;lst[a[j]]=-1;
				}
			}
			v.push_back(a[j]);mp[a[j]]++;
			lst[a[j]]=v.size();
		}
		for(int j=1;j<=m;j++){
			if(mp[j]>0) ans[j]++; 
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}

