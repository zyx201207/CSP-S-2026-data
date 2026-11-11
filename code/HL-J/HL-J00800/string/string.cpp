#include<bits/stdc++.h>
using namespace std;
int n,a[16];
string c[16];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	if(n==1){
		cout<<0;
	}else if(n==2){
		if(c[0]==c[1]||a[0]==a[1]){
			cout<<0;
		}else if(a[0]>a[1]){
			cout<<a[0]-a[1];
		}else{
			cout<<a[1]-a[0];
		}
	}
	return 0;
}