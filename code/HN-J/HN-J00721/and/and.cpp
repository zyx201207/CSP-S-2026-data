#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005],p,ma=-1;
bool st[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>a[1];
	p=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		p=p&a[i];
		ma=max(a[i],ma);
	}
	if(m==n)cout<<p;
	else cout<<ma;
}
