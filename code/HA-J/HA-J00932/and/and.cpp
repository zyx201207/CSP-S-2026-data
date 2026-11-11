#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
int cnt=0;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int>v;
	for(int i =1;i<=n;i++){
		cin>>a[i];
		v.push_back(i);
	}
	int ans=0;
	for(int j = 31;j>=0;j--){
			int yi=0;
			vector<int>u;
			for(int i = 0;i<v.size();i++){
				if((a[v[i]]>>j)&1){
					yi++;
					u.push_back(v[i]);
				}
				
			}
			if(yi>=m){
				
				ans+=(1<<(j));
				v=u;
				
			}
		
	}
	cout<<ans;
	
	
	
	return 0;
} 
