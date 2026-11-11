#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[500005];
int k;
int ans=0;
int now;
int las;
int pos=1;
int m;
int maxn=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[0]=a[1];
	for(int i=1;i<=n;i++){
		k=a[i]-a[i-1];
		now=las+(i-pos)*k;
		//cout<<k<<" "<<now<<endl;
		while(now>m){
			now-=(a[i]-a[pos++]);
		}
		if(i-pos+1>maxn)maxn=i-pos+1;
		las=now;
	}
	cout<<maxn;
}
