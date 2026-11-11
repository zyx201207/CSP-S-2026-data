#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,m;
ll a[N],c[N],h[N];
ll ans;
bool flag;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==0){
		cout<<1;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		c[i]=a[i]-a[i-1];
		if(c[i]!=c[i-1]&&i>2) flag=1;
	}
	if(!flag){
		int x=a[2]-a[1];
		for(int i=1;i<=n;i++){
			if(i*(x+x*i)/2>m) break;
			else ans=i+1;
		}
		cout<<min(ans,n);
		return 0;
	}
	for(int i=n;i>0;i--){
		h[i-1]=c[i]+h[i];
	}
	ans=1;
	for(int i=n;i>1;i--){
		ll k=0,cnt=1;
		for(int j=i-1;j>0;j--){
			if(k+h[j]-h[i]<=m){
				cnt++;
				k+=h[j]-h[i];
				ans=max(ans,cnt);
			}else{
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
