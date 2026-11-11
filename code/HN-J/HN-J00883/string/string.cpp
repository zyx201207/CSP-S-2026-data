#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n,c;
	cin>>n;
	string a[100005];
	string b;
	for(int i=1;i<=n;i++){
		cin>>c;
		cin>>b;
		for(int j=1;j<=c;j++){
			a[i]=c;
		}
		if(a[i]==a[i+i-1]){
			cout<<0;
		}
	}
	cout<<2;
	return 0;
} 

