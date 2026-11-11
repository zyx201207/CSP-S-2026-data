#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
int a[200010];

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0;
	if(m==1)cout<<a[n];
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int x=(a[i] and a[j]);
				if(x>ans)ans=x;
			}
		}
		cout<<ans;
	}
	if(m==n){
		for(int i=2;i<=n;i++){
			a[i] &= a[i-1];
		}
		cout<<a[n];
	}
	else{
		if(a[1]==0)cout<<0;
		else cout<<1;
	}
}
