#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		int t;
		cin>>t;
		cnt+=t;
		string e;
		cin>>e;
		for(int i=1;i<=t;i++) s+=e;
	}
	int cn=cnt/2+1;
	int bn=cn;
	int num=0;
	int k=2;
	for(int i=1;i<=cnt-cn;i++){
		if(s[bn]!=s[bn-k]) num++;
		bn++;
		k+=2;
	} 
	cout<<num;
} 
