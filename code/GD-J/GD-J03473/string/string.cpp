#include <bits/stdc++.h>
using namespace std;
struct stu{
	int t,b;
	char c;
}a[200005];
long long n,x,ok=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].t>>a[i].c;
		if(i>=2 && a[i].c!=a[i-1].c) ok=1;
		x+=a[i].t;
	}
	x/=2;
	if(ok) cout<<x;
	else cout<<0;
	
	return 0;
}
