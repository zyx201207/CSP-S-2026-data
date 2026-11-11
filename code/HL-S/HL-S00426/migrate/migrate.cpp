#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+200;
map<pair<int,int>,int>mp;
ll c,t,x[N],n,d,ans;
bool check(int k1,int k2,int p1,int p2,int z){
	if(mp[{p1,k1}]==z&&mp[{k1,p2}]==z&&mp[{p1,k2}]==z&&mp[{k2,p2}]==z&&mp[{p1,p2}]!=z)return true;
	else return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int z=1;z<=t;z++){	
	ans=0;
		cin>>n>>d;
		cin>>x[1];
		for(int i=2;i<=n;i++){
			cin>>x[i];
			for(int j=i-1;j>0;j--){
				if(x[i]-x[j]<=d){
					mp[{j,i}]=z;
					mp[{i,j}]=z;
				}
				else break;
			}
		}
		for(int i=2;i<n-1;i++){
			if(check(i,i+1,i-1,i+2,z)){
				int left=1,right=1;
				while(check(i,i+1,i-left-1,i+2,z)&&i-left-1>0)left++;
				while(check(i,i+1,i-1,i+right+2,z)&&i+right+2<=n)right++;
				ans+=left*right;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
