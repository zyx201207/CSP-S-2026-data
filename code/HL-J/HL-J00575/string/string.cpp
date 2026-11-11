#include <bits/stdc++.h>
using namespace std;
int m[101];
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,d=0,k;
	string b;
	cin>>n;
	k=n/2;
	while(n>0){
		int s=1;
		int a;
		string c;
		cin>>a>>c;
		s++;
		

		n--;
		for(int i=d;i<=d+a;i++){
			b[i]=c[0];
		}
		d+=a;
	}
	
	
	int sum=0,f;
	string p,q; 
	if(d%2==0){
		f=d/2;
	}else{
		f=(d+1)/2;
    }
    for(int i=0;i<f;i++){
    	if(b[i]!=b[d-i-1]){
    		sum++;
		}
	}
	cout<<sum;

	
	

	
	
	
	
		            	

	
	
	 
	
	
	
	
	
	return 0;
}
