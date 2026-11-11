#include<bits/stdc++.h>
using namespace std;
int t,n,s;
string b,c;
char a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		cin>>a;
		for(int j=1;j<=n;j++){
			b+=a;
		}
	}
	for(int i=b.size()-1;i>=0;i--){
		c+=b[i];
	}
	for(int i=0;i<b.size();i++){
		if(b[i]!=c[i]){
			++s;
		}
	}
	cout<<s/2;
	return 0;
}
