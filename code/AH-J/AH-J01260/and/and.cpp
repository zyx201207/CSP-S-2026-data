#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200001],n,k,s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	cin>>a[1];
	s=a[1];
	for(int i=2;i<=n;i++){cin>>a[i];s=s&a[i];}
	stable_sort(a+1,a+n+1);
	if(n==k)cout<<s;else cout<<a[n-k+1];
	return 0;
}
