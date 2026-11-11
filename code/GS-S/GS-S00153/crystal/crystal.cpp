#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],ans,mx,y;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		ans=1,y=m;
		for(int j=i+1;j<=n;j++){
			ans++;
			y-=(a[j]-a[j-1])*(j-i);
			if(y<0){
				ans--;
				break;
			}
		}mx=max(mx,ans);
	}cout<<mx;
	return 0;
}
