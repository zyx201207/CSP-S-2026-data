#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+10;
ll n,m,a[N],sum[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		map<ll,bool>mp;
		stack<ll>sta;
		for(int j = i;j<=n;j++){
			if(mp[a[j]]!=1){
				mp[a[j]] = 1;
				sta.push(a[j]);
			}
			else{
				while(!sta.empty()){
					ll num = sta.top();
					sta.pop();
					if(num==a[j]){
						break;
					}
					mp[num] = 0;
				}
				sta.push(a[j]);
			}
		}
		while(!sta.empty()){
			ll num = sta.top();
			sta.pop();
			sum[num]++;
		}
	}
	for(int i = 1;i<=m;i++)cout<<sum[i]<<" ";
	return 0;
}
