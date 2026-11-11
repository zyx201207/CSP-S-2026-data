#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int n;
char m[N];
string s;
int num=0;
int ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>m[i];
		for(int j=1;j<=a[i];j++){
			s[++num]=m[i];
		}
	}
	for(int i=1;i<=num/2+1;i++){
		if(s[i] != s[num-i+1]){
			ans++;
			s[i]=s[num-i+1];
		}
	}
	cout<<ans;
	return 0;
}
