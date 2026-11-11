#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a[500050]={},c[500050]={},d[500050]={};
    int g;
    map<int,int>b;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[a[j]]=0;
		}
		for(int j=i;j<=n;j++){
			c[j]=a[j];
		
			if(b[a[j]]==0){
				b[a[j]]++;
			}
			else{
				for(int k=1;k<j;k++){
					if(c[k]==c[j]){
						g=k;
						break;
					}
					
				}
				for(int k=g;k<j;k++){
					
					b[c[k]]--;
					c[k]=0;
				}
				b[c[j]]++;
			}
			
		}
		
	
	
	
	for(int j=1;j<=n;j++){
		cout<<c[j]<<" ";
	}
	cout<<endl;
		for(int j=i;j<=n;j++){
			if(c[j]!=0){
				d[c[j]]++;
				for(int k=i;k<=n;k++){
					if(c[k]==c[j]){
						c[k]=0;
					}
				}
				c[j]=0;
			}
		
		}
	
	
}
for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	
	return 0;

}
