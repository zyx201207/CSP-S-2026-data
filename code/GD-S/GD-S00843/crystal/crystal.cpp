#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define int long long
using namespace std;
const int N	= 5e5+5;
int n,m,cnt,a[N];
int nw,l,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l=1;
	for(int i=1;i<=n;i++){
		nw+=(a[i]-a[i-1])*(i-l);
		if(nw>m){
			while(nw>m){
				nw-=a[i]-a[l];
				l++;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
