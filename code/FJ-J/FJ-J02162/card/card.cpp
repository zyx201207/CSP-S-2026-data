#include<bits/stdc++.h>
using namespace std;

long long n,m,mx=0;
long long l[500022]={},ans[500022];



int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	for(int i=0;i<n;i++){
		long long p[50055]={};
		for(int j=i;j<n;j++){

			
			bool tiao=0;
			for(int k=j+1;k<n;k++){
				if(p[k]==l[j]){
					j=k-1;
					tiao=1;
				}	
			}
			if(tiao){
				continue;
			}
			p[j]=l[j];
			ans[p[j]]++;
			
		}
	
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	
	
	
	
	return 0;
}
