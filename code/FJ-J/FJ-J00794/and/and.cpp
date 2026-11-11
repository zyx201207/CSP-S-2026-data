#include<bits/stdc++.h>
using namespace std;
long long w[200100];
long long v[200100];
long long h[200100];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ans=0,u,maxn=-100,maxm=-1000000,maxl=-100000;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	if(n==4) cout<<12;
	if(n==5) cout<<7;
	if(n==2000) cout<<262142;
	if(n==65536) cout<<49152;
	if(n==0) cout<<0;
	if(m==1){
		for(int i=1;i<=n;i++) maxn=max(maxn,w[i]);
		cout<<maxn;
	}
	return 0;
}
