#include<bits/stdc++.h> 
using namespace std;
int main(){
   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);
    long long m,n,crysmax=1;
	long long crys[1000001]={},step=0,step2=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>crys[i];
	}
	sort(crys+1,crys+1+n);
	if(n==2){
		if(crys[2]-crys[1]>m)cout<<2;
		else{
			cout<<1;
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(crys[i]==crys[j]&&i!=j){
				step++;
			}
		}
	}
	crysmax+=step/2;
	for(int i=1;step2<=m;i++){
		for(int j=i+1;j<=n;j++){
			if(step2+crys[j]-crys[i]<m){
				crysmax++;
				step2+=crys[j]-crys[i];
				crys[i]+=step2;
			}
		}
	}
	cout<<crysmax;
	
	
	
	
	
	
	
	
	
	
	
	
	
	









 return 0;
} 






































