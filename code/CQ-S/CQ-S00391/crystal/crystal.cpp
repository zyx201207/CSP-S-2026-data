#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,a[500010],last,cnt,l,ans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	last=a[1];cnt=1;l=1;
	for(int i=2;i<=n;i++){
		if(last==a[i]){
			cnt++;
			ans=max(ans,cnt);
		}else{
			m-=cnt*(a[i]-last);
			while(m<0){
				m+=a[i]-a[l];
				cnt--;l++;
			}
			cnt++;last=a[i];
			ans=max(ans,cnt);
		}
	}
	cout << ans << endl;
	return 0;
}
