#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n;
long long d,x[N],f[N],ans;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			for (int j=f[i-1]+1;j>=1;j--){
				if(x[i]-x[i-j+1]<=d){
					f[i]=j;
					break;
				}
			}
			if (f[i]==3){
				ans+=f[i-1]-2;
			}
			
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
