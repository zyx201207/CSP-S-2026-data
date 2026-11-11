#include <bits/stdc++.h>
using namespace std;
int a,n,s,ans;
char c;
string st;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		s+=a;
		st+=c;
	}
	for(int i=0;i<n/2;i++){
		if(st[i]!=st[n-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
