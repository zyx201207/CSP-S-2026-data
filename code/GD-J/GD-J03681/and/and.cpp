#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
vector<vector<bool>> mp;
vector<bool> cn;
int ans=0;
void anss(int x){
	if(x==-1)
		return;
	int k=0;
	for(int i=1;i<=n;i++)
		k+=(cn[i]&&mp[i][x]);
	if(k>=m){
		for(int i=1;i<=n;i++)
			if(!mp[i][x])
				cn[i]=0;
		ans=(ans<<1)+1;
	}else
		ans<<=1;
	anss(x-1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	mp.resize(n+1,vector<bool>(30));
	cn.resize(n+1);
	int mx=-1;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		cn[i]=1;
		int k=0;
		while(x!=0){
			mp[i][k++]=(x&1);
			x>>=1;
		}
		mx=max(mx,k);
	}
	anss(mx);
	cout<<ans;
	return 0;
}

