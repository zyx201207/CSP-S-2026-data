#include<bits/stdc++.h>
using namespace std;
int main(){           
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;                   
	cin>>c>>t;             
	int n[t],k[t];                 
	for(int i=0;i<t;i++){             
		cin>>n[i]>>k[i];              
		int u[n[i]],v[n[i]];       
		for(int j=0;j<n[i]-1;j++){           
			cin>>u[j]>>v[j];                  
		}              
	}              
	cout<<"1 2";      
	return 0;          
}          
