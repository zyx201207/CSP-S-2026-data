#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int b[1000005];
int c[1000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout)
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){//计数 	
		for(int j=1;j<=n;j++){//局数 
		  a[j-1]=0;
		  		c[j]=a[j];//摆牌 
		  	 if(c[j]!=0){	
			for(int k=1;k<=j;k++){//查重 
				if(a[k]==c[j]){
					for(int q=k;q<j;q++){
						c[q]=0;//肃清 
					}
					
				}
			}
		  }
		  for(int k=1;k<=n;k++){
		  	if(c[k]==i){
		  		b[i]=b[i]+1;
			  }
		  }
		}
		cout<<b[i]<<" ";
	}
	return 0;
}
