#include<bits/stdc++.h>
using namespace std;
int n,a[200005],m=0;
string b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==b[i+1]){
			m=1;
		}else{
			m=0;
			break;
		}
	}
	if(m==1){
		cout<<0;
		return 0;
	}
	if(n==1){
		cout<<0;
	}
	return 0;
}
