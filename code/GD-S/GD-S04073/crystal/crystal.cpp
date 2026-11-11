#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,m,a[N],d[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) d[i]=a[i+1]-a[i];
	ll cnt=0,x=1,flag=0;
	while(flag==0){
		for(int i=1;i<=x;i++){
			cnt+=d[i]*i*(1ll);
		}x++;
		if(cnt<=m) cnt=0;
		else if(cnt>m) flag=1;
	}cout<<x-1<<'\n';
	return 0;
}
