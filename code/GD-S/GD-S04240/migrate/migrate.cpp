#include<bits/stdc++.h>
using namespace std;
int a[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int sum=0;
		for(int i=0;i<n;i++){
			if(a[i]+d>=a[i+1]){
				int mx=i+1,len=a[mx]-a[i];	
				
				for(int j=mx+1;j<n;j++){
					if(a[j]>a[i]+d){
						mx=j-1;
						len=a[mx]-a[i];
						break;
					}
				}
				for(int j=mx+1;j<=n;j++){
					if(a[j]<=a[mx]+d){
						for(int k=i;k<i+mx;k++){
							if(a[k]==a[j]-len&&a[k]-a[i]==a[j]-a[mx]){
								sum++;
								break;
							}
						}
					}else{
						break;
					}
				}
			}
		}
		cout<<sum-1<<"\n";
	}
	return 0;
}
