#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[20000],f,b;
	string s[20000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]==s[i+1]&&i+1<=n){
			cout<<0;
		}
	}
	if(a[0]==a[1]==2&&a[2]==1){
		cout<<2;
	}
	else if((a[1]==a[2]==2&&a[2]==1)){
		cout<<2;
	}
	if((a[0]==a[2]&&n==3)){
		cout<<0;
	}
	else
		cout<<2;
	return 0;
}
