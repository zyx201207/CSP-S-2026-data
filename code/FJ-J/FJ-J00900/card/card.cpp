#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FILE(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout);
int main(){
	FILE("card4")
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll n,m;
	cin>>n>>m;
	ll a[n],num[m]{};
	for(ll& i:a)cin>>i,i--;
	for(ll i=0;i<n;i++){
		vector<ll>ans;
		unordered_map<ll,bool>mp;
		for(ll j=i;j<n;j++){
			if(mp[a[j]]){
				while(ans.back()!=a[j]){
					mp[ans.back()]=0;
					ans.pop_back();
				}
			}else{
				ans.push_back(a[j]);
				mp[a[j]]=1;
			}
		}
		for(ll j:ans)num[j]++;
	}for(ll i=0;i<m;i++)cout<<num[i]<<" \0"[i==m-1];
}
