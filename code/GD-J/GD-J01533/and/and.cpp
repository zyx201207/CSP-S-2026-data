#include <bits/stdc++.h>
#define let long long
#define str string
#define rt return
using namespace std;
let n,m,mx,ans,
	mp[200010],a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(let i = 1;i<=n;i++)cin>>mp[i];
	if(m == 1){
		for(let i  =1;i<=n;i++) mx = max(mx,mp[i]);
		cout<<mx;
		rt 0;
	}else if(m == n){
		ans=  mp[1];
		for(let i = 2;i<=n;i++) ans = (ans&mp[i]);
		cout<<ans;
		rt 0;
	}else if( m == 2){
		for(let i = 1;i<=n;i++){
			for(let j = i+1;j<=n;j++){
				ans = max(ans,(mp[i]&mp[j]));
			}
		}
		cout<<ans;
		rt 0;
	}

	sort(mp+1,mp+1+n);
	for(let i = 1;i<=n;i++) a[i] = mp[i];
	for(let i = 1,j = n;i<=n;i++,j--) mp[i] = a[j];
	
	ans = mp[1];
	for(let i = 2;i<=m;i++) ans = (ans&mp[i]);
	cout<<ans;
	rt 0;
	
}
