#include<bits/stdc++.h>
#define int long long
const int N=1e8;
using namespace std;
int n,len,maxx,ans;
char a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int t;
		char ch;
		cin>>t>>ch;
		for(int j=len+1;j<=len+t;j++) a[j]=ch; 
		len+=t;
	}
	int mid=(len+1)>>1;
	for(int i=1;i<=mid;i++){
		if(a[i]!=a[len+1-i]) ans++;
	}
	cout<<ans;
	return 0;
}
//2
//2 a
//3 a
//6
//2 b
//1 c
//1 x
//1 d
//1 z
//1 x
