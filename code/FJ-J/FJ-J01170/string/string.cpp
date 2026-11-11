#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string s;
int n;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s+=string(a[i],c[i]);
	}
	int l=s.size();
	int ans=0;
	for(int i=0;i<l;i++){
		if(s[i]!=s[l-i-1]){
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}
