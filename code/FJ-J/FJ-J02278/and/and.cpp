#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+4;
int a[N],bt[40],dp[30][30][2];
int n,m,ans,aans;
void solve1(){
	return;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int mx=0,an;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		if(i==1)an=a[i];
		else an&=a[i];
		for(int j=0;j<=30;j++){
			if(a[i]&(1<<j))bt[j]++;
		} 
	}
	if(n<=20)solve1();
	else if(m==1)cout<<mx;
	else if(m==n)cout<<an;
	return 0;
}
