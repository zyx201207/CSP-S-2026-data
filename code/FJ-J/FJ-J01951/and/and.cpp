#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[2000005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	if(a[1]%a[m]!=0){
		cout<<a[m];
	}else{
		cout<<0;
	}
	return 0;
}
