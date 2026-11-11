#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
int n,m,a[N],pre[N];
#undef int 
int main(){
#define int long long 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int ans=1;
	for(int i=1,j=1;i<=n;i++){
		while(j<=i&&a[i]*(i-j+1)-pre[i]+pre[j-1]>m)j++;
		ans=max(ans,i-j+1);
	}	
	cout<<ans;

	return 0;
}
