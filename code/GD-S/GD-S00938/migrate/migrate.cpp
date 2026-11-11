#include<bits/stdc++.h>
using namespace std;
long long n,d,a[2000006],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t,c;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int l=1;l<=n-2;l++){
			for(int r=l+2;r<=n;r++){
				if(a[r]-a[l]<=d)continue;
				int num=0;
				for(int i=l+1;i<r;i++){
					if(a[i]-a[l]<=d&&a[r]-a[i]<=d)num++;
					if(num>2)break;
				}
				if(num==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
