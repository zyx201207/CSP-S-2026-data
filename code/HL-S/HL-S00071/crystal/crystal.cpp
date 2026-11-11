#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	bool isB=1;
	int cha=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=cha){
			isB=0;
			break;
		}
	}
	if(!isB){
		int ans=0;
		for(int i=n;i>=1;i--){
			int ans1=0;
			bool flag=0;
			for(int j=1;j<=i;j++){
				int sum=0;
				int ans2=0;
				for(int k=j;k<=i;k++){
					if(sum+(a[i]-a[k])>m){
						break;
						flag=1;
					}
					sum+=(a[i]-a[k]);
					ans2++;
				}
				ans1=max(ans2,ans1);
				if(flag) break;
			}
			ans=max(ans1,ans);
			if(flag) break;
		}
		cout<<ans;
	}else if(isB){
		int k=m/cha;
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=i;
			if(ans>k){
				cout<<i;
				break;
			}
		}
	}
	return 0;
}
