#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,cot=0,cnt=0;
int a[N],f[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	f[1]=1;
	for(int i=2;i<=n;i++){
		m-=(a[i]-a[i-1])*(i-f[i-1]);
		f[i]=f[i-1];
		while(0>m){
			m+=(a[i]-a[f[i]]);
			f[i]++;
		}
		cnt=max(cnt,i-f[i]+1);
	}
	cout<<cnt;
	return 0;
} 
