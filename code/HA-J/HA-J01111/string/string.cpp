#include<bits/stdc++.h>
using namespace std;
int a,b,n,l,zz,ans;
char c,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	string c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>s;
		for(int j=1;j<=a;j++){
			c[zz]=s;
			zz++;
		}
	}
	zz--;
	for(int i=0;i<zz/2;i++){
		if(c[i]!=c[zz-i]){
			
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

