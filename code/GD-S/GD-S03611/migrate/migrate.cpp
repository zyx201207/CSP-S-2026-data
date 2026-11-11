#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long m,a[2000050],qz[2000050];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			qz[i]=qz[i-1]+a[i]-a[i-1];
			qz[1]=0;
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				long long b[305][305];
				for(int e=0;e<=304;e++)
					for(int ee=0;ee<=304;ee++)
						b[e][ee]=0;
				b[i][0]=1;
				for(int s=i+1;s<=j;s++){
					for(int r=s-1;r>=i;r--){
						if(qz[s]-qz[r]<=m){
							for(int x=1;x<=305;x++){
								if(b[r][x])b[s][x+1]+=b[r][x];
							}
						}else break;
					}
				}
				for(int s=305;s>=1;s--){
					if(b[j][s]){
						if(b[j][s]>=2)ans++;
						break;
					}
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
