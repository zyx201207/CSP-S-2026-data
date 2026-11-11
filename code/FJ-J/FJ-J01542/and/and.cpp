#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[2000010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1) cout<<a[n];
	else if(n==m){
		ll num=a[1];
		for(int i=2;i<=n;i++){
			num&=a[i];
		}
		cout<<num;
	}
	return 0;
}