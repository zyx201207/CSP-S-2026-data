#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x,a[1000005],b[1000005],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		b[2]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=d;j++){
				b[i]+=b[i-j];
			}
		}
		for(int i=1;i<n;i++){
			for(int j=i;j<=n;j++){
				//cout<<b[j]<<"JJJJJJJ"<<b[i]<<endl;
				if(b[j]-b[i]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
