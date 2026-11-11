#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005];
int c[500005]{};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	
	for(int i=1;i<=n;i++){	
		for(int ii=i;ii<=n;ii++){
			b[ii]=a[ii];
		}
		for(int j=1;j<=n;j++){
			if(b[j]==b[i]){
				for(int d=j;d<i;d++){
					b[d]=0;
				}
			
			}
				
		}
		for(int p=1;p<=n;p++){
			for(int s=1;s<=m;s++){
				if(b[p]==s){
					c[s]++;
				}cout<<c[s]<<" ";
			}	
			
		}
		
	
		
	}
	
	
	for(int i=1;i<=n;i++){
		if(c[i]!=0){
			cout<<c[i]<<" ";
		}
	}
	return 0;
}
