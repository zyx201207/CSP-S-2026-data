#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
char b[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0,x=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i];j++){
			b[x]=c[i];
			x++;
		}
	}
	for(int i=0;i<x;i++){
		s[i]=b[i];
	}
	x--;
	for(int i=0;i<x/2;i++){
		if(s[i]!=s[x-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
