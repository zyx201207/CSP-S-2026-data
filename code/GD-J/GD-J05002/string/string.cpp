#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	
	else{
		int sum=min(a[1],a[2]);
		cout<<sum; 
	}
		
	
}
