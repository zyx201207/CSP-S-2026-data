#include<bits/stdc++.h>
using namespace std;
int n,m,a[(int)2e5+105];
int mx=-1e9;
int ans=0;
bool tw;
inline void dfs(int o,int ms,long long lasst){
	if(lasst<=ans)return;
	if(ms==0){
		ans=max(lasst,1LL*ans);return;
	}
	if(o==n+1)return;
	dfs(o+1,ms,lasst);
	dfs(o+1,ms-1,lasst&a[o]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		int l=-1e9;
		while(n--){
			int cnt;
			cin>>cnt;
			if(l<cnt)l=cnt;
		}
		cout<<l;
		return 0;
	}
	if(m==n){
		int l;
		cin>>l;
		int cnt=l;
		n--;
		while(n--){
			cin>>l;
			cnt=cnt&l;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i],mx=max(a[i],mx);
		tw=(tw&&a[i]==pow(2,i)-1)?true:false;
	}
	if(tw){
		for(int i=n;i>=1;i--){
			if(m==0){
				cout<<a[i];
				return 0;
			}
			m--;
		}
	}
	if(mx<4){
		int o[3]={0,0,0};
		for(int i=1;i<=n;i++){
			o[a[i]-1]++;
		}
		if(o[2]>=m)cout<<3;
		else if(o[2]+o[1]>=m)cout<<1;
		else cout<<0;
		return 0;
	}
	dfs(1,m,pow(2,31)-1);
	cout<<ans;
	return 0;
}
