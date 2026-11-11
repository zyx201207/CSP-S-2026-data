#include<bits/stdc++.h>
using namespace std;
long long c,t,ans=0; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>t;
	while(t--){
		long long n,d,x[2000005];
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		ans=0; 
		for(int i=1;i<=n;i++){
			for(int j=n;j>=i;j--){
				if(x[j]-x[i]<=d){
					long long jishu=0;
					for(int e=1;x[j]!=x[e];e++){
						if(x[j]-x[e]<=d){
							jishu++;
						}
					e--;
				}
				if(jishu==2) ans++;	
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}//...难，莫名其妙不输出了，就这样吧 
//.
