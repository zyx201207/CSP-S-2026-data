#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200010];
char c[200010]; 
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];}
	if(c[1]==c[n]){
		cout<<0;
	}
	else{
		cout<<1;
	}
	return 0;
}
