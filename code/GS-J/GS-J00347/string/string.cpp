#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	int n;
	cin>>n;
	int a[100010];
	string b[100010];
	string c;
	int d;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i];j++){
			c+=b[i];
		}
		d+=a[i];
	}
	if(d%2==0){
		cout<<c.size()/2;
	}else if(n==1){
		cout<<0;
	}else{
		cout<<c.size()/2-1;
	}
	return 0;
}
