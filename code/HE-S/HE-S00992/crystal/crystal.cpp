#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,a[N],m,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		ll mnm=m,j=i,op=0;
		while(mnm&&j!=0){
			mnm-=(a[i]-a[j]);
			j--;
			if(mnm>=0)
			op++;
		}
		ans=max(ans,op);
		if(op==n)break;
	}
	cout<<ans;
	return 0;
}
