#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,cnt,x,a[200010];
char y,c[200010];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
		cin >> x >> y;
		if(y==c[m]){
			a[m]+=x;
		}else{
			m++;
			a[m]=x;
			c[m]=y;
		}
	}
	int l=1,r=m;
	while(l<=r){
		if(c[l]==c[r]){
			if(a[l]<a[r]) a[r]-=a[l],l++;
			else if(a[r]<a[l]) a[l]-=a[r],r--;
			else l++,r--;
		}else{
			cnt+=min(a[l],a[r]);
			if(a[l]<a[r]) a[r]-=a[l],l++;
			else if(a[r]<a[l]) a[l]-=a[r],r--;
			else l++,r--;
		}
	}
	cout << cnt;
    return 0;
}
