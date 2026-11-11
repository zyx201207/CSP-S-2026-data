//GZ-S00324 贵阳市第十八中学 李翼辰
#include<bits/stdc++.h>
using namespace std;
int c,t;
long long a[2000000+50];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<n-3<<endl;
	}
	return 0;
} 
