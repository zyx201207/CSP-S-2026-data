#include<bits/stdc++.h>
using namespace std;
long long T,a[305],ans,d,n,c;
short b[305][305]; 
int main(){
	freopen("migrate3.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		ans=0;
		cin>>n>>d;
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>d)break;
//				b[i][j]++;
//				cout<<i<<" "<<j<<" "<<b[i][j]<<endl;
				for(int k=j+1;k<=n;k++){
					if(a[k]-a[j]>d)break;
					b[i][k]++;
//					cout<<i<<" "<<j<<" "<<k<<" "<<b[i][k]<<" "<<b[j][k]<<endl; 
				}
			}
		}
//		cout<<endl;
		for(int i=1;i<n;i++){
			for(int j=1;j<=n;j++){
//				cout<<b[i][j]<<" ";
				if(b[i][j]==2)ans++;
			}
//			cout<<endl;
		}
//		cout<<ans<<endl;
	} 
	return 0;
}
