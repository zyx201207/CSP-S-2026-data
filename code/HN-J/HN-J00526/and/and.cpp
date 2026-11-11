#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200001]={};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}if(m==1){
		int max=0;
		int cnt=0;
		for(int i=0;i<n;i++){
			if(cnt>=max){
			 	max=cnt;
			}
		}
		cout<<max;
	}
	else if(m==2){
		int max=0;
		int cnt=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
			 	cnt=a[i]&a[j];
			 	if(cnt>=max){
			 		max=cnt;
				 }
			}
		}
		cout<<max;
	}else if(m==3){
		int max=0;
		int cnt=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
			 	for(int k=j+1;k<n;k++){
			 		cnt=a[i]&a[j]&a[k];
			 		if(cnt>=max){
			 			max=cnt;
					}
				}
			}
			
		}
		cout<<max;
	} 
	else if(m==4){
		int max=0;
		int cnt=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
			 	for(int k=j+1;k<n;k++){
			 		for(int h=k+1;h<n;h++){
			 			cnt=a[i]&a[j]&a[k]&a[h];
			 			if(cnt>=max){
			 				max=cnt;
						}
					}
			 		
				}
			}
			
		}
		cout<<max;
	}
}
