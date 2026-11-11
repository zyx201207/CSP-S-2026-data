#include<bits/stdc++.h>
using namespace std;
int a[100010];
char c[100010];
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int i=1;i<=n;i++){
		    cin>>c[i];
	    }
	}
	if(n==1){
		cout<<0;
	}else if(n==2){
		if(c[1]==c[2]){
			cout<<0;
		}else if(c[1]!=c[2]){
			if(a[1]>=a[2]){
				cout<<a[2];
			}else{
				cout<<a[1];
			}
		}
	}
	return 0;
} 
