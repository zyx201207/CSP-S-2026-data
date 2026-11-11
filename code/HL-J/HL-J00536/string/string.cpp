#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int a[1100];
	char c[1001];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]==c[i+1]){
			cout<<"0";
		}	
		if(c[1]==c[n] &&c[i]==c[n-i]){
			cout<<"0";
		}
		if(c[1]!=c[n] &&c[i]!=c[n-i]){
			cout<<i*a[i];
		}
		if(c[n/2-1]==c[n/2+1]){
			cout<<"0";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
