#include<bits/stdc++.h>
using namespace std;
char c[200010],poi;
int n;
int qwe;
int tot=1;
int ans=0;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>qwe>>poi;
		for(int j=tot;j<=tot+qwe-1;j++){
			c[j]=poi;
		}
		tot+=qwe;
	}
	for(int i=1;2*i<=tot-1;i++){
		if(c[i]!=c[tot-i]) ans++;
	}
	cout<<ans;
	
}

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solve();
	return 0;
}
