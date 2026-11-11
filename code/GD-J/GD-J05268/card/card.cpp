#include<bits/stdc++.h>
using namespace std;
int n,m;
long long card[500000+10];
long long temp[500000+10];
long long ans[500000+10];
int main(){
	freopen("card","r",stdin);
	freopen("card","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>card[i]; 
		temp[i]=card[i];
	}
	int sum=1;
	for(int y=1;y<=n;y++){
		card[y]=temp[y];
		sum++;
	for(int i=sum;i<=n;i++){
				
		for(int j=i;j>=sum;j--){
			
			if(card[i]==card[j]){
				for(int x=j;x<i;x++){
					card[x]=0;
				}
			}
				
		}
		
		
		
	}
	
	for(int q=1;q<=m;q++){
 	for(int p=1;p<=n;p++){
 		if(card[p]==q)
 		ans[q]++;	
	 }
 }
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
