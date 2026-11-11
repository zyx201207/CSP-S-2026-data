#include<bits/stdc++.h>
#define N 200010
#define INF 1e18
#define int long long
using namespace std;
char b[N];
string t;
int n,s,a[N],l,r;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			t+=b[i];
		}
	}
	r=t.size()-1;
	while(l<r){
		if(t[l]!=t[r])
		s++;
		l++;
		r--;
	}
	cout<<s;
	return 0;
}
