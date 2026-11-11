#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m; 
	cin>>n>>m;
	int a[500010];
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	int f=0,t=0;
	if(m==2){
		for(long long i=1;i<n;i++){
			if(a[i]==a[n]){
				t=i-1;
				f=1;
				break;
			}
		}
		if(f==1){
			if(a[t]<a[n]){
				cout<<0<<" "<<n;
			}
			else{
				cout<<n<<" "<<0;
			}		
		}	
		if(f==0){
			if(a[t]<a[n]){
				cout<<n-1<<" "<<n;
			}
			else{
				cout<<n<<" "<<n-1;
			}
		}
	}
	return 0;
}  
