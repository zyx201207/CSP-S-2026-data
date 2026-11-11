#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ll long long
using namespace std;
int n,m;
int p[200005][35],cnt[35];
int a[200005],f[200005],cntf=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=30;j++){
			if((a[i]>>j)&1)
				p[i][j]++,cnt[j]++;
		}
	}
	ll ans=0;
	vector<int> v;
	for(int j=30;j>=0;j--){
		if(cnt[j]<m)
			continue;
		if(!ans){
			ans+=(1<<j);
			for(int i=1;i<=n;i++)
				if(p[i][j])
					v.pb(i),f[i]=1; 
			continue;
		}
		int tmp=0;
		for(auto i:v){
			if(p[i][j])
				tmp++;
		}
		if(tmp>=m){
			ans+=(1<<j);
			for(auto i:v){
				if(!p[i][j])
					f[i]=0;
			}
			v.clear();
			for(int i=1;i<=n;i++)
				if(f[i])
					v.pb(i); 
		}
	}
	cout<<ans<<endl;
	return 0;
} 
