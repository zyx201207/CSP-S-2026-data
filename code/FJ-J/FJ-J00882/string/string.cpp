#include<bits/stdc++.h>
using namespace std;
string a;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int i,x,l=0;
	char c;
	for(i=1;i<=n;i++){
		cin>>x>>c;
		l+=x;
		while(x--) a+=c;
	}
	int ans=0,s=0;
	for(i=0;i<=l/2;i++){
		if(a[i]!=a[l-i-1]) s++;
	}
	for(i=l-1;i>=l-l/2;i--){
		if(a[i]!=a[l-i-1]) ans++;
	}
	cout<<min(s,ans);
	return 0;
}
