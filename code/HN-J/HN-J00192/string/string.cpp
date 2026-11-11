#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200005];
int vis[500];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char c;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		vis[c]++;
	}
	if(n<=1){
		cout<0;
		return 0;
	}
	if(vis[c]==n){
		cout<<0;
		return 0; 
	}
	
	return 0;
}
 
