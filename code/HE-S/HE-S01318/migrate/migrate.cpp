#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n;
long long d,a[N],cnt,ans;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) {
		ans=0;
		cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++){
        	for(int j=i+1;j<=n;j++){
        		cnt=0;
        		for(int k=i+1;k<=j;k++){
        			if(a[k]-a[i]<=d&&a[j]-a[k]<=d)cnt++; 
				}
				if(cnt==2){
					ans++;
					cout<<i<<" "<<j<<endl;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
