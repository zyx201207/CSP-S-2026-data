#include<bits/stdc++.h>
using namespace std;
long long C,t,a[2000010],n,d,b[5010][5010],c[5010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>t;
	if(C==11||C==12){
		while(t--){
			long long q,ans;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			q=a[2]-a[1];
			d/=q;
			if(d<=1){
				cout<<0<<'\n';
				continue;
			}
			ans=n-d*2+1;
			if(ans<0){
				cout<<0<<'\n';
				continue;
			}
			cout<<ans<<'\n';
		}
	}
	while(t--){
		cin>>n>>d;
		long long ans=0;
		for(int i=1;i<=5000;i++){
			c[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if((a[i]-a[i-1])>d){
				c[i]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(c[j]==1){
					for(int k=j;k<=n;k++){
						b[i][k]=2147483647;
					}
					break;
				}
				b[i][j]=(a[j]-a[i]-1)/d+1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(b[i][j]!=1){
					int cnt=0;
					for(int k=i+1;k<=j-1;k++){
						if(b[i][k]+b[k][j]==b[i][j]&&(b[k][k+2]==1||b[k-2][k]==1)){
							cnt++;
						}
						if(cnt==3){
							break;
						}
					}
					if(cnt==2){
						//cout<<i<<" "<<j<<'\n';
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
//10 3
//0 3 6 7 8 9 10 13 16 19
