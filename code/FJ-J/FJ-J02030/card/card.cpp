#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long iss[5005]={0};
	long long is[5005]={0};
	long long ans[5005]={0};
	long long nnn=n;
	for(int i=0;i<nnn;i++){
		cin>>is[i];
		iss[i]=is[i];
	}
	for(int a=0;a<n;a++){
		for(int i=a;i<nnn;i++){
			for(int j=a;j<nnn-1;j++){
				if(is[i]==is[j]){
					for(int w=j;w<i;w++){
						is[w]=0;
						
					}
					
				}
				
			}
		}
		
		for(int j=a;j<n;j++){
			ans[is[j]]++;
		}
		for(int j=0;j<n;j++){
			
			is[j]=iss[j];
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
	
}
