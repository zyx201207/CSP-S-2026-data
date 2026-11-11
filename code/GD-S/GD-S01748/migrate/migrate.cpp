#include<bits/stdc++.h>
using namespace std;
int c,t;
long long a[2000007],d,n;
bool chk(int l,int r){
	if(!(a[r]-a[l+1]<=d&&a[r-1]-a[l]<=d&&a[r]-a[l]>d&&r-l>=3)) return 0;
	for(int i=l+2;i<=r-2;i++){
		if(a[i]-a[l]<=d&&a[r]-a[i]<=d) return 0;
	}
	return 1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","W",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	//cout<<c<<endl;
	while(t--){
		cin>>n>>d;
		//cout<<n<<" "<<d<<endl;
		for(int i=1;i<=n;i++){
			cin>>a[i]; 
		}
		if(!(c>=11&&c<=12)){
			long long ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(chk(i,j)){
						ans++;
					//	cout<<i<<" "<<j<<endl;
					}
				}
			}
			cout<<ans<<endl;
		}
		else if(c>=11&&c<=12){
			long long x=d/(a[2]-a[1]);
			if(a[2]-a[1]==0||x==0){
				cout<<0<<endl;
				continue;
			}
			if(x>=3){
				cout<<0<<endl;
				continue;
			}
			long long ans=(n-1)/x;
			cout<<ans<<endl;
		}
	}
	return 0;
}
