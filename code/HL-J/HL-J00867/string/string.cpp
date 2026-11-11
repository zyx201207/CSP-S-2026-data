#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
string s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;int flag1=1,flag=1;long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	string ss;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++) ss+=s[i];}
	long long len=ss.length();ans=0;
	long long l=0,r=len;
	while(l<=r){
		if(ss[l]!=ss[r]) ans++;
		l++;r--; 
	}
	cout<<ans;
	return 0;
}