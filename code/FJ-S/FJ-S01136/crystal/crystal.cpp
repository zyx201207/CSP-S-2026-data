#include<bits/stdc++.h>
using namespace std;
long long n,mm,b[500012],a[500012],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>mm;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(b+1,b+1+n);
	
	for(int j=n;j>=1;j--){
		for(int i=1;i<=n;i++){
			a[i]=b[i];
		}
		long long s=0,m=mm;
		
		for(int i=j;i>=1;i--){
			
			if(a[j]-a[i]<=m){
				m-=(a[j]-a[i]);
				
				s++;
				ans=max(ans,s);
			}
		
			else{
				break;
			}
			
			
		}
		
	}
	cout<<ans;
	return 0;
}
