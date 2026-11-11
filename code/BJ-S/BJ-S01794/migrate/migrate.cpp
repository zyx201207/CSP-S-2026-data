#include<bits/stdc++.h>
using namespace std;
long long c=0,t=0,n=0,d=0,a[2000001]={},s[5001][5001],f[5001][5001],ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<t;++i){
		ans=0;
		cin>>n>>d;
		if(n>5000)n=5000;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int o=0;
				s[i][j]=ceil((a[j]-a[i])/d);
				for(int k=i+1;k<j;k++){
					if(s[i][k]+s[k][j]==s[i][j]){
						o++;
						if(o>2)break;
					}
				}
				if(o==2)ans++;
			}
		}
		
		for(int i=1;i<=n;i++){
			a[i]=0;
			for(int j=1;j<=n;j++){
				s[i][j]=0;
				f[i][j]=0;
			}
		}
		cout<<ans<<"\n";
	}
}
