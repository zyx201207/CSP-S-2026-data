#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","s",stdout);
	bool ll=1;
	int n,c=0,mi=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		c+=a[i];
		if(b[i]!=b[i-1]){
			ll=0;
		}
	}
	if(ll=1){
		cout<<0;
		return 0;
	}
	mi=c/2+c%2;
}
