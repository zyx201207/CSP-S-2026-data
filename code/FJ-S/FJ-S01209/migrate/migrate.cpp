#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ulp(i,a,b) for(int i=a;i<=b;i++)
#define dlp(i,a,b) for(int i=a;i>=b;i--)
const int N=2e6+5;
int c,t,n,d,a[N],f[N],step[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ans=0;
		ulp(i,1,n)cin>>a[i];
		ulp(i,1,n-1){
			f[i]=1,step[i]=0;
			ulp(j,i+1,n){
				int ff=0,minst=N;
				dlp(k,j-1,i){
					if(a[j]-a[k]>d)break;
					if(step[k]<minst){
						minst=step[k],ff=f[k];
					}
					else if(minst==step[k]){
						ff+=f[k];
					}
				}
				f[j]=ff,step[j]=minst+1;
				if(f[j]==2){
					++ans;
					//cout<<"**"<<i<<" "<<j<<" "<<f[j]<<" "<<step[j]<<"**\n";
				}
			}
		}
		cout<<ans<<"\n";
	}
}
