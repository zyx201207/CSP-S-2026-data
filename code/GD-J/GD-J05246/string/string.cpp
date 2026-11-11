#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long n,a[200001],t[200001],cnt=1,pos=1,con,flag,ans;
long long cut;
string c[200001];
string s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cut+=a[i];
		con+=a[i];
	}
	if(con%2==0){
		flag=1;
	}
	else{
		flag=0;
	}
	cut/=2;
	for(int i=0;i<cut;i++){
		s1+=c[pos];
		cnt++;
		if(cnt==a[pos]+1){
			cnt=1;
			pos++;
		}
	}
	for(int i=cut;i<con;i++){
		if(flag==0){
			flag=1;
			continue;
		}
		s2+=c[pos];
		cnt++;
		if(cnt==a[pos]+1){
			cnt=1;
			pos++;
		}
	}
	for(int i=0;i<cut;i++){
		if(s1[i]!=s2[con-i-cut-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0; 
} 
