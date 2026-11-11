#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10; 
long long CCC,t,a[N],n,d,s,ans;
bool yy[5005][5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>CCC>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n&&a[j]-a[i]<=d*(j-i);j++){
				bool vis=0;
				for(int k=i+1;k<j;k++){
					if(a[k]-a[i]==a[j]-a[k]&&(a[k]-a[i]<=d)&&2*(a[k]-a[i])==(a[j]-a[i])){
						if(!yy[i][j]&&!yy[j][i]){
							vis=1;
							break;
						}
					}
				}
				if(vis&&!yy[i][j]&&!yy[j][i]){
					ans++;
					yy[i][j]=yy[j][i]=1;
				}	
			}
		}
		cout<<ans/2<<"\n";
	}
	return 0;
}
