#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[100005],b[100005];
	cin>>n;
	if(n<=1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<+n;i++){
		if(b[i]==b[1]){
			cout<<0;
		}
	}
	
	
	
	return 0;
} 
