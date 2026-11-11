#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string c,b,d;
	long long n,a,ans=0,x=0,v=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		for(int j=0;j<a;j++){
			c+=b;
		}x+=a;
	}
	b=' ';
	for(int i=0;i<x/2+1;i++){
		b[i]==c[i];
	}
	for(int i=x-1;i>=x/2;i--){
		if(c[i]!=b[v])ans++;v++;

	}
	cout<<ans;
	return 0;
}
 
