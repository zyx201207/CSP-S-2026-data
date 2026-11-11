#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring> 
using namespace std;
int n,m;
int a[5000005];
int cnt[5000005];
int ans[5000005];
vector<int> s;
int main(){
	ios::sync_with_stdio(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			while(cnt[a[j]])cnt[s.back()]--,s.pop_back();
			s.push_back(a[j]);
			cnt[a[j]]++;
		}
		while(!s.empty())ans[s.back()]++,cnt[s.back()]--,s.pop_back();
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
}
