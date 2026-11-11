#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int c,t,n,cnt;
long long d,x[2000005];
//if(abs(x[i]-x[j])<=d)
//
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		memset(x,0,sizeof(x));
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		
		cout<<cnt;
		cnt=0;
	}
	return 0;
}
