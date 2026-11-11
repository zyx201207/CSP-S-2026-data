#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 10;
int n,m;
vector<int>v,a,aa;
int s[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	for(int i = 0;i<n;i++){
		a.erase(a.begin(),a.end());
		aa.erase(aa.begin(),aa.end());
		for(int j = i;j<n;j++){
			sort(aa.begin(),aa.end());
			if(v.size()){
				if(a[lower_bound(aa.begin(),aa.end(),v[j]) - aa.begin()] != v[j]){
					a.push_back(v[j]);
					aa.push_back(v[j]);
				}
				else{
					a.erase(lower_bound(aa.begin() + j,aa.end(),v[j]) ,a.end());
					aa.erase(lower_bound(aa.begin() + j,aa.end(),v[j]) ,aa.end());
					a.push_back(v[j]);
					aa.push_back(v[j]);
				}
			}else{
				a.push_back(v[j]);
				aa.push_back(v[j]); 
			}
		}
		sort(aa.begin(),aa.end());
		for(int i = 1;i<=m;i++){
			s[i] += (upper_bound(aa.begin(),aa.end(),i) - aa.begin()) - (lower_bound(aa.begin(),aa.end(),i) - aa.begin());
		}
	}
	for(int i = 1;i<=m;i++)cout<<s[i]<<" ";
	return 0;
}

