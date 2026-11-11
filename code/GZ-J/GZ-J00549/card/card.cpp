//GZ-J00549 贵阳市南明区新世界学校 文希昊 
#include<bits/stdc++.h> 
using namespace std;

int n,m,l;
long long a[600005]={},sum;

int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[n];
	}
	for(int i=1;i<=m;i++){
		sum=0;
		for(int j=1;j<=n;j++){
			if(a[j+i-1]==a[j]){
				for(int k=j+i;k<=n;k++){
					a[k]=0;
				}
				sum=sum+n-j+i;
			}
		}
		long long ans=0;
		for(int j=1;j<=sum;j++){
			if(a[i]==a[j]){
				ans++;
			}
		}
		cout<<ans<<' ';
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
