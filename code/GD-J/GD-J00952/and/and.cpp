#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+50;
int n,m,f[maxn],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>f[i];
	int l=1,r=n;
	for(int i=30;i>=0;i--){
		sort(f+l,f+r+1);
		int it=lower_bound(f+l,f+r+1,(1<<i))-f;
		if(r-it+1>=m) ans+=(1<<i),l=it;
		for(int j=l;j<=r;j++) f[j]=f[j]%(1<<i);
	}
	cout<<ans;
	return 0;
}
