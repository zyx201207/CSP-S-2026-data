#include<bits/stdc++.h>
using namespace std;

const int N=5e5,lg=19;

int n;
long long m;
long long a[N+5];
long long s[N+5];

int ck(int l,int r){
	if(l<1 || r>n){
		return 0;
	}
	return (a[r]*(r-l+1)-(s[r]-s[l-1])<=m);
}

int solve(){
	int ans=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;++i){
		int p=i+1;
		for(int g=lg;g>=0;--g){
			if(ck(p-(1<<g),i)==1){
				p-=(1<<g);
			}
		}
		ans=max(ans,i-p+1);
	}
	return ans;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	cout<<solve();
	return 0;
}//answer 100pts
