#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
const int INF=0x3f3f3f3f;
int a[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int w=0,l=1,ans=0;
	for(int i=2;i<=n;i++){
		w+=(a[i]-a[i-1])*(i-l);
		while(w>m){
			w-=a[i]-a[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
}

