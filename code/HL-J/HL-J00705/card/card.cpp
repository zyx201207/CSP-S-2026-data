#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,a[100]={},m1[10]={},b[10][100]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			int tf=0;
			b[i][j]=a[i-1+j];
			for(int w=1;w<j;w++){
				if(b[i][w]==b[i][j]){
					tf=1;
				}
				if(tf==1){
					b[i][w]=0;
				}
			}
			for(int w=1;w<=j;w++){
				cout<<b[i][w];
			}
			cout<<endl;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			for(int w=1;w<=m;w++){
				if(b[i][j]==w){
					m1[w]+=1;
					break;
				}
			}
		}
	}
		
		
		
	for(int i=1;i<=m;i++){
		cout<<m1[i]<<' ';
	}
	return 0;
}