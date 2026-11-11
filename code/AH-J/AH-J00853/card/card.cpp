#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
typedef long long ll;
ll n,m,a[N],cnt[N];
map<int,ll>mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
		mp.clear();
		for(int j=i;j<=n;j++){
			if(mp[a[j]]!=1){
				mp[a[j]]++;    
			}	
			else{
				mp.clear();
				mp[a[j]]++;
			}
		}
		for(auto it=mp.begin();it!=mp.end();it++){
			if(it->second!=0){
			   cnt[it->first]++;
		   }
	   }
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
    return 0;
}
