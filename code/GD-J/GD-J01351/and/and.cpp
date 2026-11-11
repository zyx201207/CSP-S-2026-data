#include<bits/stdc++.h>
using namespace std;
//#define int long long
int a[1000000],pre[1000000];
int vis[1000000];
int n,k;
signed main(){
	freopen("and.in","r",stdin);//¼ÇµÃ¿ª£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡ 
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for (int i=1; i<=n; i++){
		cin>>a[i];
	}
	pre[0]=1;
	for (int i=1; i<=30; i++){
		pre[i]=pre[i-1]*2;
	}
	sort(a+1,a+n+1);
	int ans=a[n];
	for (int i=1; i<k; i++){
		ans&=a[n-i];
	}
	cout<<ans;
} 
