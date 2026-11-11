#include<bits/stdc++.h>
using namespace std;
int n,a[51],f=0,d=0;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	char c[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		if((a[i-1]!=a[i])&&(i!=0)){
			f=1;
		}
		if((c[i-1]!=c[i])&&(i!=0)){
			d=1;
		}
	}
	if(n<=1){
		cout<<0;
		return 0;
	}
	else if(d==0){
		cout<<0;
	}
	else if((f=0)&&(a[0]==1)){
		cout<<n/2;
		return 0;
	}
	else if(n==2){
		if(a[1]>=a[2]){
			cout<<a[2];
		}
		else{
			cout<<a[1];
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
