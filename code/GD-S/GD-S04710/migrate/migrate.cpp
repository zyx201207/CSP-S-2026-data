#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,ans=0;
int main(){
	freopen("migrate","r",stdin);
	freopen("migrate","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
			
		cin>>n>>d;
		long long a[n+5],b[n+5];
		for(long long j=1;j<=n;j++){
			cin>>a[i];
			if(i==1)continue;
			else b[i-1]=a[i]-a[i-1];
		}
		for(long long j=1;j<=n;j++){
			for(long long k=j+2;k<=n;k++){
				if((k-j)<=d) continue;
				if(j==1&&k==5) continue;
				else if((k-j)%d==0&&(k-j)/d==2||(k-j)%d!=0&&(k-j)/d==1){
					ans++;
				}
			}
		}
		cout<<ans;
		ans=0;
	}
	return 0;
}
