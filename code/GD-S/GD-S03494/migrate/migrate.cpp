#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e6+5;
ll c,t,n,d,a[maxn],cnt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ll fs;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(d==1){
			cout<<0<<endl;
			continue;
		}
		fs=d/(a[2]-a[1]);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(j-i>1 && (a[j]-a[i])%fs!=0){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
		cnt=0;
	}
	return 0;
}
//Oct31==Dec25?
