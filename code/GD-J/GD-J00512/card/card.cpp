#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,a[50001],m,x=0,y=0,d[50001]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long b[5001]={0};
		for(int j=i;j<=n;j++){
		     if(b[a[j]]==0){
		     	d[a[j]]++;
		     	b[a[j]]=1;
		   
			 }
			 else {
			 	b[a[j]]=2;
			 	int n=j-1;
			 	while(b[a[n]]!=2){
			 		 b[a[n]]==0;
			 		d[a[n]]--;
			 		n--;
				 }
				 
				b[a[j]]==0;
				
			 }
		}
	
    }
		for(int i=1;i<=m;i++){
			cout<<d[i]<<" ";
		} 
}
