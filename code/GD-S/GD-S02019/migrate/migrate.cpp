#include<bits/stdc++.h> 
using namespace std;
#define lint long long
lint x[20002];
int dp[20002];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	
for(int pp=0;pp<t;pp++){
int ans=0;
	int n;
	lint d;
	cin>>n>>d;
	int de01=0;
	for(int i=0;i<n;i++){
		cin>>x[i];
		if(x[i]-x[de01]<=d){
			dp[de01]=i;
			
			
		}
		else{
				for(int j=de01+1;j<=i;j++){
					if(x[i]-x[j]<=d){
						de01=j;
						dp[j]=i;
						break;
					}
				}
			}
			for(int j=de01+1;j<=i;j++){
				if(x[i]-x[j]<=d){
					dp[j]=i;
				}
			}
		}
	
	
	
	
	
	for(int i=0;i<n-2;i++){
		for(int j=i+3;j<n;j++){
			int count=0;
			for(int k=dp[i];k>=dp[i]-2;k--){
//				cout<<"111"<<endl;
				if(dp[k]>=j){
					count++;
				}
				
				else if(dp[k]==0 and k!=0){
					count++;
				}
			
			}
			
		    if(count==2){
			ans++;
		    }    
		}
	}
	
	
	cout<<ans<<endl;
}
//	cout<<de01;
//	for(int i=0;i<n;i++){
//		cout<<dp[i]<<endl;
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
