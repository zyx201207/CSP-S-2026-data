#include<bits/stdc++.h>
using namespace std;
long long n,i,l=1,m,num;
long long a[200100][100];
char b;
int B;
int main(){

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	m=n;
	for(i=1;i<=n;i++){
		cin>>a[i][1]>>b;
		B=b;
		a[i][2]=B;
	}
	
	for(i=10;i>=0;){
		if(a[l][1]>a[m][1]){
			if(a[l][2]==a[m][2]){
				a[l][1]=a[l][1]-a[m][1];
				m=m-1;
				if(m==l){
					cout<<num;
					return 0;
				}
			}
			else{
				a[l][1]=a[l][1]-a[m][1]; 
				num=num+a[m][1];
				m=m-1;
				if(m==l){
						cout<<num;
						return 0;
					}
			}
			
			
			
		}	
else{
		if(a[l][1]<a[m][1]){
			if(a[l][2]==a[m][2]){
				a[m][1]=a[m][1]-a[l][1];
				l=l+1;
				if(m==l){
					cout<<num;
					return 0;
				}
			}
			else{
			a[m][1]=a[m][1]-a[l][1]; 
			num=num+a[l][1];
			l=l+1;
			if(m==l){
					cout<<num;
					return 0;
				}	
			}
			
			
		}
	else	{
	if(a[l][1]==a[m][1]){
			if(a[l][2]==a[m][2]){
				m=m-1;
				l=l+1;
				if(m==l||l>m){
					cout<<num;
					return 0;
				}
			}
			else{
			num=num+a[l][1];
			l=l+1;
			m=m-1;
			if(m==l||l>m){
					cout<<num;
					return 0;
				}	
			}
			
		}	
	}
		
		
		
			
		}
		
		
	}
	return 0;
}
