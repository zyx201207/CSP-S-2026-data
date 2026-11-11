#include<bits/stdc++.h>
using namespace std;
string a;
long long ans,n,m;
__int128 k;
char c;
int main(){
//	freopen("string3.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>m>>c; 
		for(long long j=1;j<=m;j++){
			a+=c;
		}
	}
	for(long long i=0;i<a.size()/2;i++){
		if(a[i]!=a[a.size()-1-i]) ans++;
	}
	cout<<ans;
	return 0;
}
