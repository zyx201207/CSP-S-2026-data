#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int a,b,c=-1,m=b;
	cin>>a>>b;
	b=b-1;
	m=m-1;
	int k[a];
	for(int i=0;i<=a-1;i++){
		cin>>k[i];
	}   
	int max=-1;
	
	while(b>=0){
		if(b<m){
			int q=-1;
			for(int i=0;i<=a-1;i++){
				for(int j=0;j<=a-1;j++){
				if(k[i]&k[j]>q)q=k[i]&k[j];	
				}
			}
			max=max&q;
		}
		for(int i=0;i<=a-1;i++){
			for(int j=0;j<=a-1;j++){
				if((k[i]&k[j])>max)max=k[i]&k[j];
			}
		}for(int i=0;i<=a-1;i++){
			for(int j=0;j<=a-1;j++){
				if((k[i]&k[j])==max)k[i]=-1,k[j]=-1;
			}
		}
		
		b--;
	}
	cout<<max;
	return 0; 
}
