#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10,V=50;
vector<ll> buck[V];
ll a[N];
ll n,m,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		buck[32].push_back(a[i]);
	}
	int lst=32;
	for(int j=31;j>=0;j--){
		for(int i=0;i<buck[lst].size();i++){
			int num=buck[lst][i];
			if((num>>j)&1){
				buck[j].push_back(num);
			}
		}
		if(buck[j].size()<m){
			continue;
		}
		else{
			ans+=(1<<j);
			lst=j;
		}
	}
	cout<<ans;
	return 0;
}

