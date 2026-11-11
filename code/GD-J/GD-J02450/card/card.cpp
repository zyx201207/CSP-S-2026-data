#include <bits/stdc++.h>
#define int long long
using namespace std;
int cnt[300005];
int a[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		vector<int> p;
		map<int,int> mp;
		for(int j=i;j<n;j++){
			if(mp[a[j]]==0){
				p.push_back(a[j]);
				mp[a[j]]=p.size();
				
			}else{
				int k=mp[a[j]]-1;
				int r=p.size()-1;
				while(r>=k){
					p.erase(p.begin()+r);
					r--;
				}
				p.push_back(a[j]);
				mp[a[j]]=p.size();
				
			}
		}
		for(int y=0;y<p.size();y++){
			cnt[p[y]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
