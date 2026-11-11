#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int W=2e5+5;
ll n,m,a[W],lg[100];
vector<ll> b,c;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	lg[0]=1;
	for(int i=1;i<=30;i++){
		lg[i]=lg[i-1]*2;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bool flag=0;
		for(int j=1;j<=30;j++){
			if(a[i]==lg[j]){
				c.push_back(a[i]);
				flag=1;
				break;
			}
		}
		if(!flag){
			b.push_back(a[i]);
		}
	}
	sort(c.begin(),c.end());
	sort(b.begin(),b.end(),cmp);
	for(int i=1;i<m;i++){
		if(i<b.size()) b[0]&=b[i];
		else b[0]&=c[i-b.size()];
	}
	cout<<b[0];
	return 0;
}
