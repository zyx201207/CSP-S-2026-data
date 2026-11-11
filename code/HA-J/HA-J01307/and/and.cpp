#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll m,n;
	cin>>m>>n; 
	vector<ll> p(m);
	for(int i=0;i<m;i++){
		cin>>p[i];
	}	
	sort(p.begin(),p.end(),cmp);
	cout<<p[n-1]<<endl;
	return 0;
}
