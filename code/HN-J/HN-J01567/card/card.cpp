#include<bits/stdc++.h>
using namespace std;

int a[500001],ans[300001],n,m;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int i=1;
	while(i<=n){
		int b[500001]={0};
		for(int j=1;j<=n-i+1;j++){
			bool f=false;
			for(int g=1;g<=j-1;g++){
				if(f){
					b[g]=0;
				}else{
					if(b[g]==a[i]){
						b[g]=0;
						f=true;
					}
				}
			}
			b[j]=a[i];
		}
		for(int j=1;j<=n-i+1;j++){
			if(b[j]!=0){
				ans[b[j]]++;
			}
		}
		i++; 
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" "; 
	}
	return 0;
}
