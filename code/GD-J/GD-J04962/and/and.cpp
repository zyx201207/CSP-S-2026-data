#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int x,y;
	cin>>x>>y;
	int sum=0;//×î´ó 
	int a[9999]={};
	
	
	if(y==2){
	for(int i=1;i<=x;i++){
		cin>>a[i];
		}
	for(int i=1;i<=x-y+1;i++){
		for(int j=i+1;j<=x-y+2;j++){
			int b1=a[i],b2=a[j];
			sum=max(sum,(b1&b2));
			}
		}
    }
    
    
    if(y==3){
	for(int i=1;i<=x;i++){
		cin>>a[i];
		}
	for(int i=1;i<=x-y+1;i++){
		for(int j=i+1;j<=x-y+2;j++){
			for(int j2=j+1;j2<=x-y+3;j2++){
					int b1=a[i],b2=a[j],b3=a[j2];
					sum=max(sum,(b1&b2&b3));
				}
			}
		}
    }
    
    
    if(y==4){
	for(int i=1;i<=x;i++){
		cin>>a[i];
		}
	for(int i=1;i<=x-y+1;i++){
		for(int j=i+1;j<=x-y+2;j++){
			for(int j2=j+1;j2<=x-y+3;j2++){
					for(int j3=j2+1;j3<=x-y+4;j3++){
						int b1=a[i],b2=a[j],b3=a[j2],b4=a[j3];
						sum=max(sum,(b1&b2&b3&b4));
					}
				}
			}
		}
    }
	cout<<sum;
	return 0;
}
