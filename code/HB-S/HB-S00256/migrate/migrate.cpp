#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,m=0,h=30000000;
int a[2000005],b[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t>0){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		
		for(int i=1;i<n-3;i++){
			int k=i+3;
			if(a[k]-a[i]<=d){
				k++;
			}
			else{
				if(a[k]-a[k-1]<d&&a[k]-a[k-2]<d){
					ans++;
				}
			}
		}
	cout<<ans<<endl;
	t--;
	}
	return 0;
}
