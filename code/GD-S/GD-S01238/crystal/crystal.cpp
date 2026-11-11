#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int main(){
freopen("crystal.in","w",stdin);
freopen("crystal.out","r",stdout);
    
	long long n,m;
	cin>>n>>m;
	int ans=0,k=m;
	int b,s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		b+=a[i];
	}
	s=b/n;
	for(int i=0;i<n;i++){
		
			if(a[i]!=s&&k!=0){
				k-s+a[i];
				ans++;
			}
			
		
	}
	if(ans>0){
		cout<<ans-1;
	}else{
		cout<<ans;
	}
	
	return 0;
} 
