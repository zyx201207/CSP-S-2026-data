#include <bits/stdc++.h>
#define int long long 
using namespace std;
int n,m;
int a[500010];
int t[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[i]=a[i];
	}
	int cnt;
	int ans=0;
	sort(a+1,a+1+n);
	
	for(int i=n;i>=2;i--){
		cnt=1;
		int m1=m;
		for(int j=i-1;j>=1;j--){
			if(m1>=a[i]-a[j]){
				cnt++;
				m1=m1-a[i]+a[j];
				
			}else{
				break;
			}
			
			

		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
