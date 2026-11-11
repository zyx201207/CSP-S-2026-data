#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
//   freopen("card.in","r",stdin);
//    freopen("card.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int> fs(n);
    vector<pair<int,int>> lk(n);
    vector<pair<int,int>> pdb(m+1,{-1,-1});
    for(int i=0;i<n;i++){
		cin>>fs[i];
		lk[i]=pdb[fs[i]];
		lk[i].second++;
		pdb[fs[i]]=lk[i];
		pdb[fs[i]].first=i;
	}
	vector<bitset<500001>> cnt(m+1);
	for(int i=0;i<n;i++){
		stack<pair<int,int>> q;
		map<int,int> mp;
		for(int j=i;j<n;j++){
			if(mp.find(fs[j])!=mp.end()){
				/*while(q.top().second>=mp[fs[j]]){
					mp.erase(q.top().first);
					q.pop();
				}*/
			}else mp[fs[j]]=i;
			q.push({fs[j],j});
		}
		while(!q.empty()){
			cout<<q.top().first<<' ';
			cnt[q.top().first][i]=1;
			q.pop();
		}
		cout<<'\n';
	}
	for(int i=1;i<=m;i++) cout<<cnt[i].count()<<' ';
    return 0;
}
//pdboynbkls
