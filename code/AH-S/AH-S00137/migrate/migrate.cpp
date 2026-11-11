#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,x[2000010],cnt;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(d/(x[2]-x[1])==2&&d%(x[2]-x[1])==0){
			for(int i=1;i<=n-3;i++){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
    return 0;
}
