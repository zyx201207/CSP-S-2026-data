#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],flag=0,ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		flag=0;
		ans=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		for(int l=1;l<=n-3;l++){
			for(int r=l+3;r<=n;r++){
				flag=0;
				for(int i=l;i<=r;i++){
					if(abs(x[i]-x[l])<=d&&abs(x[i]-x[r])<=d) flag++;
				}
				if(flag==2) {
					//cout<<l<<" "<<r<<endl;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//0 2 4 2 1 2 3 4 5 2 1 2 3 4 5
//0 2 5 3 -2 -1 0 1 2 6 2 -4 -3 -2 -1 3 6

