#include<bits/stdc++.h>
using namespace std;
long long n,cnt,x[1000000],y,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++){
		ans=max(ans,x[i]&x[j]);
	}
	cout<<ans;
	return 0;
}
