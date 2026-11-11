#include<iostream>
#include<cmath>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100]={0},b[100][2]={0};
	
	for(int i=1;i<=m;i++){
		b[i][0]=i;
	}
	cin>>a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
		for(int l=0;l<n;l++){
			
		}	
		for(int j=0;j<i;j++){
			
			if(a[j]==a[i]){
				for(int l=j;l<i;l++){
					a[l]=0;
				}
			}
			
		}	
		for(int l=0;l<n;l++){
			b[a[l]][1]+=1;
		}	
		
	}
	for(int i=1;i<n;i++){
		cout<<b[i][1]<<' ';
	}
	return 0;
}
