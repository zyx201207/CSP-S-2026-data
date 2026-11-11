#include<bits/stdc++.h>
using namespace std;
long long n,a[251115],cnt;
char c[251115];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(c[i]==c[i+1]){
			cout<<"0";
			return 0;
		}
	}
	return 0;
}