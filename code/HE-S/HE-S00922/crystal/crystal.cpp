#include<bits/stdc++.h> 
using namespace std;
int a[1000000],b[1000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m,ans=0,san=1,c;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		c=m;
		for(int j=i-1;j>=0&&c>0;j--){
			if(a[i]-a[j]<=c){
				c=m-a[i]+a[j];
				san++;
				
			}
			
		}
		ans=max(ans,san);
		san=1;	
		
	}
	
	cout<<ans;


	return 0;
}
