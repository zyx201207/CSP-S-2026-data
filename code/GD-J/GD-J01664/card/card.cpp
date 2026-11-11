#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],b[1000005],c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int k=1;k<=n;k++){
		int p=0,q=1;
		for(int i=k;i<=n;i++){
		q=q-p;
		bool flag=1;
		for(int j=1;j<q;j++){
			if(b[j]==a[i]){
				flag=0;
			}
			
		}
		if(flag==1){
			b[q]=a[i];
		}else{
			p=0;
			for(int j=1;j<q;j++){
				
				b[j]=0;
				p++;
			}
			
			b[q-p]=a[i]; 
		}
		
		
		q++;
		
		}
		for(int j=1;j<=q;j++){
			for(int r=1;r<=q;r++){
				if(b[r]==j){
					c[j]++;
				}	
			}
			
		}
	}
	
	
	
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}




