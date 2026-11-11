#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+1;
int n,m,a[N],s[N]={},ans=0;
int find(int x){
	int l=1,r=x-1;
	int d,cnt;
	while(l<=r){
		d=l+r>>1,cnt=a[x]*d-(s[x-1]-s[x-d-1]);
		if(cnt>m) r=d-1;
		else if(cnt<m) l=d+1;
		else return d+1;
	}
	return l;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int q=find(i);
		ans=max(ans,q);
	}
	cout<<ans;
	return 0;
} 
