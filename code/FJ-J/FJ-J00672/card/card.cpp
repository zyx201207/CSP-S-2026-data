#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[m];
	int b[m]={0}; 
	int y=0;
	for(int i=y;i<n;i++){
		int x;
		cin>>x;
		a[i]=x;
		b[x]++; 
		if(i!=1){
		for(int j=y;j<i;j++){
			if(a[j]==a[i]){
				y=i;
				break;
			}		
			}

		}
		
	}
	for(int i=0;i<m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
