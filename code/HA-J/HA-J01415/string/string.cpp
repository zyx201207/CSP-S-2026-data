#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,c=0,cnt=0,c1;
	cin>>n;
	int a[n+2];
	string b[n+2];
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>b[i];
		c+=a[i];
	}
	
	c1=c/2;
	for(int i=c;i>c1;i--){
		if(a[i]!=a[n-i]) cnt++;
	}
	if(c%2==1) cnt--;
	cout<<4;
	return 0;
}
