#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a;
string sz;
char b;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>b;
		for(int j=m;j<=m+a;j++){
			sz[j]=b;
		}
		m+=a;
	}
	int ans=0;
	for(int i=0;i<m;i++){
		if(sz[i]!=sz[m-i-1]) ans++;
	}
	cout<<ans/2;
	return 0;
} 
