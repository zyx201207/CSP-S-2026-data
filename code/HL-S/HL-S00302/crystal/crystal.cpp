#include <bits/stdc++.h>
using namespace std;
#define ll long long
int maxn=0;
ll n,m;
ll a[500005];
ll d[500005];
int zl[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}          
	sort(a+1,a+n+1);
	int i=1;
	int cnt=0;
	while(i<=n){
		int j=i+1;
		for(j;j<=n;j++){
			if(a[j]!=a[j-1]) break;
		}
		zl[++cnt]=i;
		i=j;
	}
	
	for(int y=1;y<=cnt && n-zl[y]>=maxn;y++){
		int u=zl[y];
		ll p=0;
		for(int i=2;i<=n-u;i++){
			p+=(i-1)*(a[i+u]-a[i-1+u]);
			if(p>m){
				maxn=max(maxn,i-1);
				break;
			}
		}
	}
	cout<<maxn<<endl;
	return 0;
}               