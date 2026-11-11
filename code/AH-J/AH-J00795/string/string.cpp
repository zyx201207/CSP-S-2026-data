#include<bits/stdc++.h>
using namespace std;
long long n,a[200000+10];
char c;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdin);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
	}
    if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(a[1]==a[2]){
			cout<<0;
		}
		else{
			cout<<1;
		}
		return 0;
	}
	
	
	
	return 0;
}
