#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,ans;
ll a[200009],c[200009];
bool cmp(const ll x,const ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int p=a[1];
	for(int i=1;i<=m;i++){
		p&=a[i];
	}
	cout<<p;
}
