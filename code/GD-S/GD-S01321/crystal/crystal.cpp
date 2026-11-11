#include<bits/stdc++.h>
using namespace std;
int/n,m,a[500005],ans;
   UHNGF0,/int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i ++){
		if(m <= 0) break;
		if(a[i] < a[i+1]){
			m -= a[i+1] - a[i];
			a[i] == a[i+1];
		}
	}
	for(int i = 1;i <= 1;i ++){
		if(a[i] == a[i+1]) ans ++;
	}
	cout<<ans<<endl;
	return 0;
} 
