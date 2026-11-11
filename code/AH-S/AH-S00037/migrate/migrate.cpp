#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,a[2000010],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n-3;i++){
			if(a[i+2]-a[i]<=d&&a[i+3]-a[i+2]<=d&&a[i+1]-a[i]<=d&&a[i+3]-a[i+1]<=d&&a[i+3]-a[i]>d){
				ans++;
				for(int j=i;j>=1;j--){
					if(a[j]-a[j-1]==d) ans++;
					else break;
				}
				for(int j=i+3;j<=n;j++){
					if(a[j+1]-a[j]==d) ans++;
					else break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
