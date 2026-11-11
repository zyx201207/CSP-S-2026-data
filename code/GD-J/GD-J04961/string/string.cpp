#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n;
ll a[N],ans;
char c[N];
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		ll m=min(a[l],a[r]);
		a[l]-=m,a[r]-=m;
		if(c[l]!=c[r])
			ans+=m;
		if(!a[l])l++;
		if(!a[r])r--;
	}
	cout<<ans;
	return 0;
}
