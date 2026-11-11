#include <bits/stdc++.h>
using namespace std;
string s;
long long l,n,a[1000010];
char c[1000010];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	if(n==1){
		cout<<"0";
		return 0;
	}
	if(n==2){
		if(c[1]==c[2]){
			cout<<"0";
			return 0;
		}
		else {
			cout<<min(a[1],a[2]);
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
		l+=a[i]; 
	cout<<l/2;
	return 0;
}
