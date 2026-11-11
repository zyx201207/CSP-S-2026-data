#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t,n,d,a[N],p[N]; 
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					p[i]++;
				}else{
					break;
				}
			}
		}
		int s=0;
		for(int i=1;i<=n;i++){
			for(int j=i+p[i]+1;j<=n;j++){
				int t=(a[j]-a[i])/d;
				s++;
				if(a[j]-a[i]==t*d){
					s--;
				}
			}
		}
		cout<<s<<'\n';
	}
	return 0;
}
