#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,sum=0,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i]; 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(a[k]-a[j]<d&&a[i]-a[k]<d)
						sum++;
				}
				if(sum==2)
					sum=0,ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}

