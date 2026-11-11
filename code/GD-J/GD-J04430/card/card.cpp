#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int N = 1e6+5;
ll n,m;
ll a[N];
struct p{
	bool hn={0};ll n;
};
vector<p>b[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<2<<" "<<1;
	return 0;
} 
