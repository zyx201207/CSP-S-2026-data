#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[200005],loga=0,ans=0,maxa=-1;
bool u[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	long long x;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i)u[i]=true;
	for(int i=1;i<=n;++i)maxa=max(a[i],maxa);
	while(maxa!=0){
		++loga;
		maxa>>=1;
	}
	for(long long int i=loga-1;i>=0;--i){
		int x=0;
		for(int j=1;j<=n;++j)if(u[j]==true&&(a[j]&(1LL<<i)))++x;
		if(x>=m){
			ans+=(1LL<<i);
			for(int j=1;j<=n;++j)if(!(a[j]&(1LL<<i)))u[j]=false;
		}
	}
	cout<<ans;
	return 0;
}
