#include<bits/stdc++.h>
using namespace std; 
int main(){
	int n,m,maxx=0;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//ÊäÈë 
	cin>>n>>m;
	int a[n],c[n][n];
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			c[i][j]=a[i]&a[j];
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<n;j++){
			for(int k = j;k<n;k++){
				if(c[i][j]>=c[j][k] && c[i][j]>=c[j][k]){
					maxx=c[i][j];
				}
			}
		}
	}
	cout<<maxx<<endl;
	return 0;
}
