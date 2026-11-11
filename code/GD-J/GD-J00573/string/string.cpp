#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m=0,c=0,num=0,k=0,d=0; 
	cin>>n;
	long long x[n];
	string z,y,a,b;
	for(int i=0;i<n;i++){
		cin>>x[i]>>z[i];
		m+=x[i];
	}
	for(int i=0;i<n;i++){
		k+=x[c];
		for(int j=d;j<k;j++){
			y[j]=z[i];
			d=j;
		}
		d++; 
		c++;
	}
	c=0;
	for(int i=0;i<m/2;i++){
		a[i]=y[i];
	}
	for(int i=m-1;i>m/2;i--){
		b[c]=y[i];
		c++;
	}
	for(int i=0;i<m/2;i++){
		if(a[i]!=b[i]){
			num++;
		}
	}
	cout<<num;
	return 0;
}
