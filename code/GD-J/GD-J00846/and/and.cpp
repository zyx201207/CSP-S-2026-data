#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int ans=-1;
vector<int> a;
bool cmp(int x,int y){
	return x>y;
}
void dfs(int id,int num,int tot){
	if(id==n+1){
		if(num==m)ans=max(ans,tot);
		return;
	}
	int tot1=tot,tot2=tot;
	if(num==0)tot2=a[id];
	else tot2=tot2 & a[id];
	dfs(id+1,num,tot1);
	dfs(id+1,num+1,tot2);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	map<int,int> mp;
	int pw=1;
	mp[1]=1;
	for(int i=1;i<=20;i++){
		pw*=2;
		mp[pw]=1;
	}
	cin >> n >> m;
	a.resize(n);
	for(int i=1;i<=n;i++)cin >> a[i];
	if(n<=20){
		dfs(1,0,0);
		cout << ans;
		return 0;
	}
	else if(n<=2000){
		if(m==1){
			int mx=-1;
			for(int i=1;i<=n;i++)mx=max(mx,a[i]);
			cout << mx;
			return 0;
		}
		if(m==n){
			int tmp=a[1];
			for(int i=2;i<=n;i++)tmp=tmp&a[i];
			cout << tmp;
			return 0;
		}
		if(m==2){
			int mx=-1;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					mx=max(mx,a[i]&a[j]);
				}
			}
			cout << mx;
			return 0;
		}
	}
	else{
		bool flg=true,flg2=true;
		for(int i=1;i<=n;i++){
			if(mp[a[i]+1]!=1)flg=false;
			if(a[i]>4)flg2=false;
		}
		if(flg){
			sort(a.begin()+1,a.end(),cmp);
			cout << a[m];
			return 0;
		}
		map<int,int> ct;
		if(flg2){
			for(int i=1;i<=n;i++)ct[a[i]]++;
			if(ct[4]>=m)cout << 4;
			else if(ct[3]>=m)cout << 3;
			else if(ct[2]>=m || ct[2]+ct[3]>=m)cout << 2;
			else if(ct[1]>=m || ct[1]+ct[3]>=m)cout << 1;
			else cout << 0;
			return 0;
		}
	}
	return 0;
}
