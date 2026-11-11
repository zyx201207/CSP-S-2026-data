#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=2*1e6+10;
int c,t,n,d,cnt=0;
int x[INF];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","W",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		memset(x,0,n+1);
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+d;j<=min(n,i+2*d-1);j++){
				if(((j-i)<d&&(j-i)==2)||((j-i)/d==1&&(j-i)%d==0&&(x[j]-x[i])%d==0)||((j-i)%d==0&&d==2)||j-i>=2*d||(d>1&&(j-i)>3)){
					continue;
				}
				cout<<i<<" "<<j<<":"<<endl;
				bool flag=true;
				for(int k=i+1;k<=j;k++){
					if(x[k]-x[k-1]>d){
						flag=false;
					}
				}
				if(flag==true){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
		cnt=0;
	}
	return 0;
}
