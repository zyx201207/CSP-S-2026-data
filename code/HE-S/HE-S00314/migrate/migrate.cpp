#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,d,a[N];
int ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>t; while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		} 
		for(int i=2;i<=n;i++){
			int l=i-1,r=i+1;
			if(a[r]-a[l]<=d){
				ans++;
			} 
			else{
				continue;
			} 
			if(r<n&&a[r+1]-a[r]<=d&&a[r+1]-a[l]>d){
				r++;ans++;
				while(r<n){
					ans+=r-i-1;
				}
				if(l>1&&a[i]-a[l-1]<=d){
					l--;ans+=r-i;
					while(l>1&&a[i]-a[l-1]<=d){
						ans+=(r-i)*(i-l-1);
					}	
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
