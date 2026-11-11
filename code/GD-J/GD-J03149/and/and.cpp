#include<bits/stdc++.h>
using namespace std;
long long int m,n,a[100001],b[100001],sum=0,p=0,q;
int s(int k){
	for(int i=1;i<=n;i++){
	if(k==1){
	for(int j=1;j<=n;j++){
		sum=a[j];
		b[j]=1;
		s(k+1);
		sum=0;
		b[j]=0;
	}	
	}
		
	else if(b[i]==0){
		q=sum;
		sum=sum&a[i];
		b[i]=1;
	}	
	if(k==m){
		p=max(p,sum);
		return 0;
	}
	else{
		s(k+1);
		sum=q;
		b[i]=0;
	}	
	}
	
	
	
	
}


int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);

cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
} 
s(1);
cout<<p;

return 0;	
} 
