#include<bits/stdc++.h>
#define ll long long
#define N 500010
using namespace std;
int n;
ll ans,a[N],m,tp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	tp=m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ll tmp=1;
		m=tp;
		for(int j=i-1;j>=1;j--){
			if(a[j]==a[i]) tmp++;
			else if(m>=a[i]-a[j]) m-=a[i]-a[j],tmp++;
			else break;
		}
		ans=max(tmp,ans);
	}
	cout<<ans;
	return 0;
}
