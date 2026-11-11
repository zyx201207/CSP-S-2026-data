#include <bits/stdc++.h>
using namespace std;
int a[10005];
string s[100005],z[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=0,x=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s;
		
		z[i]+=a[i]*s;
	}
	for(i=1;i<(n+1)/2;i++){
		if(size.s[i]!=size.s[n+1-i])
		x++;
	}
	cout <<x<<endl;
	return 0;
}
