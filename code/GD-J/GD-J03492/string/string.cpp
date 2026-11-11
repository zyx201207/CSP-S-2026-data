#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],m,num,si=1;
char c[1000000000],s[1000000000];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s[si]=c[i];
			si++;
		}
	}
	for(int i=1;i<=si/2;i++){
		if(s[i]!=s[si-i])num++;
	}
	cout<<num;
	return 0;
}
/*

*/

