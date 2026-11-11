#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
string str;
/*
1 OK
2 OK
3 OK
4 OK
5 OK
6 OK
7 OK
8 OK
9 OK
10 OK
11 OK
12 OK
13 NO
14 NO
15 NO
16 NO
17 OK
18 OK
19 OK
20 OK
21 OK
22 NO
23 NO
24 NO
25 NO
*/
int a[200010],max_a;
char c[200010];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		max_a=max(max_a,a[i]);
	}
	for(int i=1;i<=n;i++) str+=string(a[i],c[i]);
	for(int i=0,j=str.size()-1;i<=j;i++,j--){
		if(str[i]!=str[j]) ++ans;
	}
	cout<<ans;
	return 0;
}
