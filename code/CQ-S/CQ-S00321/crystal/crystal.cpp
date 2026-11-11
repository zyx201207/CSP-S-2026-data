#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,m,a[N],ans,cnt;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int c=m;
	for(int i=n;i>=1;i--){
		c+=(a[i+1]-a[i])*(cnt-1);
		for(int j=i-cnt;j>=1;j--){
			c-=a[i]-a[j];
			if(c<=0||j==1){
				if(c<0)cnt=i-j,c+=a[j]-a[i];
				else cnt=i-j+1;
				ans=max(ans,cnt);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
