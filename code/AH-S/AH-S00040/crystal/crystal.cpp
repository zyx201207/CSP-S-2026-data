#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],zs[500005],maxt,l,r;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)zs[i]=zs[i-1]+(a[i]-a[i-1])*(i-1);
	if(n==1){
		cout<<1;
		return 0;
	}
	l=1;
	maxt=1;
	for(int i=2;i<=n;i++){
		while((zs[i]-zs[l]-(l-1)*(a[i]-a[l]))>m)l++;
		maxt=max(maxt,i-l+1);
	}
	cout<<maxt;
	return 0;
}
