#include<bits/stdc++.h>
using namespace std;
int s[50001],b[20001],n,m,ans,bns;
int main(){
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	
		cin>>s[i];
		
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=i;k<j;k++){
				if(s[j]==s[k]){
					ans=j;
				}
			}
			
			}for(int j=ans;j<=n;j++){
				b[j]++;
				}
		} 
		

		for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';		
		}
	
	
	
	return 0;
}
