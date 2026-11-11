#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	long long n,s=0,g=0,t=0;
	char c[200010];
	cin>>n;
	for(int i=1;i<=n;i++){	
		cin>>a[i]>>c[i];
		s+=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(g+t>=s/2) break;
		for(int j=n;j>i;j--){
			if(!a[i]) break; 
			if(c[i]!=c[j]){
				if(a[j]){
					if(a[i]>=a[j]){
						g+=a[j];
						a[i]-=a[j];
						a[j]=0;	
					} 
					else{
						g+=a[i];
						a[j]-=a[i];
						a[i]=0;
					}
				}
				
			} 
			else{
				if(a[j]){
					if(a[i]>=a[j]){
						t+=a[j];
						a[i]-=a[j];	
						a[j]=0;
					} 
					else{
						t+=a[i];
						a[j]-=a[i];
						a[i]=0;
					}
				}
			}
		}	
	}
	cout<<g<<endl;
	return 0;
}
