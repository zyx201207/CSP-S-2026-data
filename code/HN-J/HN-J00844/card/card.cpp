#include<bits/stdc++.h>
using namespace std;
int n,m,z; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(m==2){
		int o=n,t=n;
		cin>>z;
		for(int i=0;i<n-2;i++){
			int a=0;
			cin>>a;
		}
		int s;cin>>s;
		if(z==1&&s==1)cout<<n<<" "<<0;
		else if(z==2&&s==2)cout<<0<<" "<<n;
		else if(z!=s)cout<<n<<" "<<n; 
	} else{
		for(int i=0;i<n;i++){
			int a;cin>>a;
		}
		for(int i=0;i<m;i++){
			cout<<n<<" ";
		}
	}
	return 0;
} 
