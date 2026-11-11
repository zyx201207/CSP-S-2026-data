#include <bits/stdc++.h>
using namespace std;

int main (){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin >>n>>m;
	int pai[n];
	int paii[n];
	int c[m];
	for (int i=0;i<n;i++){
		cin>>pai[i];
		paii[i]=pai[i];
	}
	for(int j=0;j<m;j++){
		c[j]=0;
	}
	for(int q=0;q<n;q++){
		for (int g=0;g<n;g++){
		paii[g]=pai[g];
		}
		for (int r=0;r<q;r++){
			if (pai[q]==pai[r]){
				for(int p=0;p<=r;p++){
					paii[p]=0;
					
				}
			}
			if(paii[r]!=0){
				c[r]++;
			}
			
		}	
	}
	for (int v=0;v<m;v++){
		cout << c[v]<<" ";
	}

	return 0; 
}
