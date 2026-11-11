#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7,M=3e5+7;
int n,m,a[N],c[M];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		deque<int>q;
		map<int,int>mp;
		for(int j=i;j<=n;j++){
			if(mp[a[j]]){
				while(mp[a[j]]){
					mp[q.back()]--;
					q.pop_back();
				}
				mp[a[j]]++;
			}
			else mp[a[j]]++;
			q.push_back(a[j]);
		}
		for(auto j:mp) c[j.first]+=j.second;
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
4 3
1 2 1 3
*/
