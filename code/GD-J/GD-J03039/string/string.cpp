#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n;cin>>n;
	long long a[n+5];
	char b[n+5];
	for(int i=0;i<n;i++)cin>>a[i]>>b[i];
	if(n==1)cout<<0;
	if(b[0]==b[1])cout<<0;
	if(b[0]!=b[1]){
		if(a[0]==a[1]){
			cout<<a[0];
		}else{
			cout<<abs(a[0]+a[1]-max(a[0],a[1]));
		}
	}
	return 0;
}
