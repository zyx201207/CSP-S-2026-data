#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	char c;
}s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c ;
		l+=s[i].a;
	}//
	string s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s[i].a;j++) s+=s[i].c;
	}
	//for(int i=1;i<=n;i++) q.push_back(a[i]);
	long long ans=0LL;
	int left=0,right=n-1;
	for(int i=0;i<n;i++){
		if(s[i]!=s[n-i]) ans++;
	}
	cout<<ans;//
	return 0;
}