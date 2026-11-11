//GZ-J00210 ∫Î“„÷–—ß —Ó∫∆”Ó 
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	vector<int> x;
	for(int i=1;i<=n;i++) {
		int y;
		cin>>y;
		x.push_back(y);
	}
	sort(x.begin(),x.end(),cmp);
	
	 cout<<x[m-1]<<"\n";
	return 0;
} 


