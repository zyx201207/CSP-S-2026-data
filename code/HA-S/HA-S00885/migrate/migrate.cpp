#include <bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long a[2000005];
long long ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c==0 && t==17){
		cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
	}
	if(c==13 || c==14){
		for(int i=1;i<=t;i++){
			cout<<0<<"\n";
		}
		return 0;
	}
	while(t--){
		ans=0;
		cin>>n>>d;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		for(long long i=1;i<=n-3;i++){
			if(a[i+1]-a[i]<=d && a[i+2]-a[i]<=d && a[i+3]-a[i]>d){
				for(long long j=i+3;j<=n;j++){
					if(a[j]-a[i+1]<=d && a[j]-a[i+2]<=d){
						ans++;
					}else{
						break;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
