#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int a[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n-3;i++){
			int x1=a[i],x2=a[i+1],x3=a[i+2],x4=a[i+3];
			int c1=x2-x1,c2=x3-x2,c3=x4-x3;
			if(c1==c2&&c2==c3&&c1<=d&&x4-x1>d){
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
