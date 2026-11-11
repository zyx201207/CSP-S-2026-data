#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+10;
int b[2*maxn],n,m;
void solve1(){
	int maxx=-1;
	for(int i=1;i<=n;i++){
		maxx=max(maxx,b[i]);
	}
	cout<<maxx;
}
void solve2(){
	int sum=b[1];
	for(int i=1;i<=n;i++){
		sum&=b[i];
	}
	cout<<sum;
}
void solve3(){
	int maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int s=b[i]&b[j];
			maxx=max(maxx,s);
		}
	}
	cout<<maxx;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(m==1) solve1();
	else if(m==n) solve2();
	else if(m==2) solve3();
	return 0;
} 
