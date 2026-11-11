#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	int x=0;
	string m;
	int a[n];
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	for(int j=1;j<=a[i];j++){
    		cin>>m;
		}
	}
	for(int k=sizeof(m);k>=1;k--){
		do{
			x+=a[k];
		}while(m[k]!=m[k-1]);
	}
	cout<<x;
	return 0;
} 
