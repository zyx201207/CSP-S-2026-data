#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int MAXN=200005;
int a[MAXN];
char b[MAXN];
void js(string &a,int n,char b){
	for(int i=1;i<=n;i++){
		a+=b;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	char x;
	cin>>a[0]>>b[0];
	x=b[0];
	int flag=1;
	string s;
	js(s,a[0],b[0]);
	int j=0;
	j+=a[0];
	for(int i=1;i<n;i++){
		cin>>a[i]>>b[i];
		js(s,a[i],b[i]);
		if(x!=b[i]){
			flag=0;
		}
		j+=a[i];
	}
	if(flag==1){
		cout<<0;
	}
	else{
		int ans=0;
		j=j-1;
		for(int i=0;i<s.size()/2;i++){
			if(s[i]!=s[j-i]){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}
