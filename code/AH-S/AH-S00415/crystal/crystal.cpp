#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],c[N],sum,ans;
int L,R,len;
void add(){
	sum+=len*c[++R];
	len++;
	return;
}
void del(){
	sum-=(a[R]-a[L++]);
	len--;
	return;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	while(R<n){
		add();
		while(sum>m){
			del();
		}
		ans=max(ans,len);
	}
	cout<<ans;
	return 0;
}
