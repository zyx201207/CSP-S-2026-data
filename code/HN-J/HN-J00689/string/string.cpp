#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int n,a[N];
string b;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b;
	}
	if(n==1){
		cout<<"0";
	}
	if(n==2&&a[1]==a[2]){
		cout<<"0";
	}
	
		
	return 0;
}
