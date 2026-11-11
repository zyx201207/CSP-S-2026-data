#include<bits/stdc++.h> 
#define int long long  
using namespace std;     
const int N=1e6+10;  
int c,t,n,k,s=1,u[N],v[N];       
signed main(){          
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);        
	cin.tie(0),cout.tie(0);        
	cin>>c>>t;             
	while(t--){                
		cin>>n>>k;                          
		for(int i=1;i<=n;i++){                    
			cin>>u[i]>>v[i];                
		}                                      
		cout<<s<<endl;
		s++;                                                
	}                                                   
	                                                             
	return 0;
}
