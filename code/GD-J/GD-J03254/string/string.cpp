#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,l,r;
ll ans;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	l=1;r=n;
	while(l<r){
		int x=min(a[l],a[r]);
		if(c[l]!=c[r]) ans+=x;
		a[l]-=x;a[r]-=x;
		if(!a[l]) l++;
		if(!a[r]) r--;
	}
	cout<<ans;
	return 0;
}
