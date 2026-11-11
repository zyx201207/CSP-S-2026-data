#include<bits/stdc++.h>
#define du double
#define ll long long
using namespace std;
const int M=2e5+5;
int n,m;
long long a[M],maxx=-1;
map<int,int>mp;
void dfs(int idx,int shu,long long yu){
	if(shu==m){
		maxx=max(yu,maxx);
		return;
	}
	if(idx>=n)return;
	
	dfs(idx+1,shu,yu);
	dfs(idx+1,shu+1,yu&a[idx]);
}
bool pd(int x){
	ll mm=1;
	for(int i=1;i<=30;++i){
		mm*=2;
		if(mm-1==x)return 1;
	}return 0;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	ll amx=-1;
	bool m1=1,m2=1,mn=1,ma=1;
	for(int i=1;i<=n;++i){
		cin>>a[i];mp[a[i]]++;
		if(a[i]!=1)m1=0;
		if(a[i]!=2)m2=0;
		if(a[i]!=n)mn=0;
		if(pd(a[i])==0)ma=0;
		amx=max(amx,a[i]);
	}
	if(m1){
		for(int i=1;i<=n;++i){
			maxx=max(maxx,a[i]);
		}cout<<maxx;
	}else if(m2){//10 10 10 10
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				maxx=max(maxx,(a[i]&a[j]));
			}
		}cout<<maxx;
	}else if(mn){
		maxx=a[1];
		for(int i=2;i<=n;++i){
			maxx=maxx and a[i];
		}cout<<maxx;
	}else if(amx<=4){
		if(n-m>=mp[0]){
			if(amx==4){
				if(mp[4]>=m)cout<<4;
				else if(mp[3]>=m)cout<<3;
				else if(mp[3]+mp[2]>=m)cout<<2;
				else if(mp[1]+mp[3]>=m)cout<<1;
				else cout<<0;
			}
		}else{
			cout<<0;
		}
	}else if(ma){
		if(n-m<mp[0])cout<<0;
		else {
			sort(a+1,a+n+1,cmp);
			cout<<a[m];
		}
	}else{
		dfs(0,0,1);
		cout<<maxx;
	}
	return 0;
}
