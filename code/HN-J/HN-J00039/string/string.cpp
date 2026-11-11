#include<bits/stdc++.h>
using namespace std;
long long d,n,a[1000000];
char c[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	
	if(n==1){
		cout<<"0";
		return 0;
	}
	
	else if(n<=2){
		if(c[0]==c[1]){
			cout<<"0";
		}
		else{
			if(a[0]<a[1]) cout<<a[0];
			else cout<<a[1];
		}
		return 0;
	}
	else{
		int x=n-1,i=0,b=0;
		if(n%2==0) b=n/2;
		else b=(n+1)/2;
		
		while(i<b){
			if(a[i]<a[x]){
				if(!(c[i]==c[x])){
					d+=a[i];
				}
				a[x]-=a[i];
				i++;
			}
			else{
				if(!(c[i]==c[x])){
					d+=a[x];
				}
				a[i]-=a[x];
				x--;
			}
			if(a[i]==0){
				i++;
			}
			else if(a[x]==0){
				x--;
			}
			
			
		}	
	}
	cout<<d;
	
	return 0;
}
