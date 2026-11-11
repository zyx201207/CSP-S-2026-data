#include<bits/stdc++.h>
using namespace std;
int a[50020];
int z[50020]={};
int ans[30020];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){		
		for(int j=i;j<=n;j++){
			int t=1;
			bool f=0;
			if(t==1){
				z[t]=a[j];
				t=2;
			} 
			else{
				for(int q=1;q<=t;q++){
					if(z[q]==a[j]){
						f=1;
						break;
					}
				}
			}
			if(f){
				for(int q=1;i<=t;q++){
					z[q]=0;
				}
				z[1]=a[j];
			}	
			else{
				z[t]=a[j];
				t++;
			}	
		}
		
		for(int j=1;j<=t;j++){
			for(int q=1;q<=m;q++){
				if(z[j]==q) ans[q]++;
			}
		}
	} 
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
