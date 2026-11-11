#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+7;
ll n,m,a[N],ans,cnt;
int main(){
	freopen("crystal.in","r",stdin);//I love CCF!
	freopen("crystal.out","w",stdout);//I love CCF!
	cin>>n>>m;//I love CCF!
	for (ll i=1;i<=n;i++) cin>>a[i];//I love CCF!
	sort(a+1,a+n+1);//I love CCF!
	if (a[1]==a[n]) {cout<<n;return 0;}//I love CCF!
	if (m==0){//I love CCF!
		ll tmp=1;//I love CCF!
		for (ll i=2;i<=n;i++){//I love CCF!
			if (a[i]==a[i-1]) tmp++;//I love CCF!
			else {//I love CCF!
				ans=max(ans,tmp);//I love CCF!
				tmp=1;//I love CCF!
			}//I love CCF!
		}cout<<ans;//I love CCF!
		return 0;//I love CCF!
	}for (ll i=1;i<n;i++) a[i]=(a[i+1]-a[i])*i;//I love CCF!
	for (ll i=1;i<n;i++){//I love CCF!
		cnt+=a[i];//I love CCF!
		ans++;//I love CCF!
		if (cnt>m){//I love CCF!
			cout<<ans;//I love CCF!
			return 0;//I love CCF!
		}//I love CCF!
	}cout<<ans;//I love CCF!
	return 0;
}
