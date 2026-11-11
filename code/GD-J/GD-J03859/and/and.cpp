#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int s[N][35];
int v[N],a[N];
int n,m;
int l;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int j=0,x=a[i];
		while(x>0){
			s[i][++j]=x%2;
			x/=2;
		}
		l=max(j,l);
	}
	while(l>0){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(v[i]) continue;
			if(s[i][l]==1) cnt++;
		}
		if(cnt<m){
			l--;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(v[i]) continue;
			if(s[i][l]==0) v[i]=1;
		}
		l--;
	}
	int cnt=0,ans=-1;
	for(int i=1;i<=n;i++){
		if(v[i]) continue;
		if(ans==-1) ans=a[i];
		else ans&=a[i];
		cnt++;
		if(cnt==m) break;
	}
	if(ans==-1) cout<<0;
	else cout<<ans;
	return 0;
} 
