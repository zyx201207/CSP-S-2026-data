#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,now,p,ans;
bool a[200005][35],b[35];
vector<int> v[35];
int fun(int x){
	int cnt=0;
	for(int i=0;i<v[x].size();i++){
		if(a[v[x][i]][x]) cnt++;
	}
	return cnt;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>now;
			ans=max(now,ans);
		}
		cout<<ans<<"\n";
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&now);
		p=0;
		while(now){
			if(now&1){
				a[i][p]=1;
				v[p].push_back(i);
			}
			p++,now>>=1;
		}
	}
	for(int i=30;i>=0;i--){
		if(fun(i)>=m){
			b[i]=1;
			ans+=(1ll<<i);
			for(int j=1;j<=n;j++){
				if(a[j][i]==0){
					for(int k=0;k<=30;k++) a[j][k]=0;
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
//T3
