#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long ans;
int a[N];
char c[N];
int l=1,r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	while(l<r){
		int minn=min(a[l],a[r]);
		if(c[l]!=c[r])
			ans+=minn;
		a[l]-=minn,a[r]-=minn;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	cout<<ans<<'\n';
	return 0;
}
//n ¡Ü2e5 
//S.size() ¡Ü1e9
/*
aabbc
aabba
aabaa
*/
