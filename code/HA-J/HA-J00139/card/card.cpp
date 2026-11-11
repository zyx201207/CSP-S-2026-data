#include<bits/stdc++.h>
using namespace std;
int n,m,a[10],c[10],ans1,ans2;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
	}else{
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int l=1;l<=n;l++){
					c[l]=a[l];
				}
				if(c[j]==c[i]&&j!=i){
					for(int k=i+1;k<=j-1;k++){
						c[k]=c[j];
					}	
				}
				
				
			}
			if(c[i]==c[n]&&c[i]==1){
				ans1++;
			}else if(c[i]==c[n]&&c[i]==2){
				ans2++;
			}else if(c[i]!=c[n]){
				ans1++;
				ans2++;
			}
			
		}
	}
	return 0;
}
