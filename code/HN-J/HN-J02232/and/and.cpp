#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	int n,m;
	cin>>n>>m;
	long long a[n];
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	
	if(m==1){
		int max=0;
		for (int i=0;i<n;i++){
			if(a[i]>max){
				max=a[i];
			}
		}
		cout<<max;
	}
	else if(m==n){
		int max=a[0];
		for(int i=1;i<n;i++){
			max&=a[i];
		}cout<<max;      
	}
	else if(m==2){
		int max=0;
		for(int i=0;i<n;i++){


			for(int j=i+1;j<n;j++){
				int p=a[i]&a[j];
				if(p>max){
					max=p;
		
				}
			}
		}cout<<max;
	}
	else if(m==3){
		int max=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int q=j+1;q<n;q++){
					int p=a[i]&a[j]&a[q];
					if(p>max){
						max=p;
					
					} 
				}
			}
		}cout<<max;
	}
	
	
	return 0;
} 
