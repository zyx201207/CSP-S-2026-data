#include<bits/stdc++.h>
using namespace std;
int n,ans,cnt;
long long a[500005],m,b[500005],x,k;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) b[i]=a[i]-a[i-1];
	if(n>=30000){
		for(int i=1;i<=n;i++){
			if(b[i]*(i-1)<=x){
				x-=(b[i]*(i-1));
				ans++;
			}
			else break;
		}
		cout<<ans;
		return 0;
	}
	for(int j=1;j<=n;j++){
		x=m,k=j;
		for(int i=j;i<=n;i++){
			if(b[i]*(i-k)<=x){
				x-=(b[i]*(i-k));
				cnt++;
			}
			else break;
		}
		ans=max(ans,cnt);
		cnt=0;
	}
	cout<<ans;
	return 0;
}
