#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
string b[200005],c;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<a[i];j++){
			c+=b[i];
		}
	}
	cout<<c;
	//加强回调紫狗 
	//3 2 a 2 b 2 c
	return 0;
}
