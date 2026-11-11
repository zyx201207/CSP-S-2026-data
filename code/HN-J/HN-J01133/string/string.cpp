#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[n];
	char c;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(n==1){
			cout<<"0"; 
		}else if(a[i]==a[1]){
			cout<<"0";
		}
	}
	return 0;
}
