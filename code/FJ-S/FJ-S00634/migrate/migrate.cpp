#include<bits/stdc++.h>
using namespace std;
//long long ans,c,n,m,d,q,x,y;
long long c,t,n,d,x,a[2000005],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		ans=0;
		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		if(n<=3){
			cout<<0<<endl;
			continue;
		}
		for(int j=3;j<n;j++){
			if(abs(a[j]-a[j-1])<=d&&abs(a[j-1]-a[j-2])<=d&&abs(a[j-2]-a[j-3])<=d){
				//cout<<2;
				ans++;
			}
			//cout<<abs(a[j]-a[j-3]);
		}
		cout<<ans<<endl;
	}
}

