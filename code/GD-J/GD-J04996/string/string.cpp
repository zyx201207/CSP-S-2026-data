#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m,l,j;
	long long o;
	cin>>n;
	int a[n];
	string b[n];
	m = 0;
	l = 0;
	for(int x=0;x<n;x++){
		cin>>a[x];
		cin>>b[x];
		m=m+a[x];
	}
    string z[m];
    for(int x=0;x<n;x++){
    	for(int j=0;j<a[x];j++){
    	    z[l]=b[x];
    	    l=l+1;
        }
	}
	o = 0;
	for(int x=0;x<l/2;x++){
		if(z[x]!=z[l-1-x]){
			o=o+1;
		}
	}
	cout<<o<<endl;
    return 0;
}  
