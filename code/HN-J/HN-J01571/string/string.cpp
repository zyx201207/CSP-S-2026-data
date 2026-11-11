#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;
int a[200005];
char b[200005];
string s="";
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	int j=s.size();
	for(int i=0;i*2<s.size();i++){
		if(s[i]!=s[j]){
			ans++;
		}
		j--;
	}
	cout<<ans;
	return 0;
}

