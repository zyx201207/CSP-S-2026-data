#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll n,a[N],ans=0;
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	freopen("string6.in","r",stdin);//调试用
//	freopen("string.out","w",stdout);//调试用
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	ll l=1,r=n;
	while(l<r){
		ll m=min(a[l],a[r]);
		if(s[l]!=s[r]){	
			ans+=m;
		}
		a[l]-=m;
		a[r]-=m;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	} 
	cout<<ans;
	return 0;
}
 
