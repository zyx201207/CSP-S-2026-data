#include <bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	int n,m;
	cin>>n>>m;
	int a[n+1];
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int b[n+1];
	b[1]=0;
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];          
		
	}

	
	 
	int ji=0;
	for(int i=1;i<=n;i++){
		int sum=0;
		int k=0;
		int shu=1;
		for(int j=i+1;j<=n;j++){
			if(sum+b[i]*shu>m){
				break;
			}else{
				sum=sum+b[j]*shu;
				k++;
				shu++;
				
			} 
		}
	
		ji=max(ji,k); 
		
	}
	cout<<ji;

} 
