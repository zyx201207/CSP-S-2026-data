#include<bits/stdc++.h>
using namespace std;
int c,t;
int a[2000005];
int b[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		int ans=0;
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>1){
				b[i]=min(b[i-1],b[i-2])+1;
				if(i>=3&&b[i-1]==b[i-2]){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
}
