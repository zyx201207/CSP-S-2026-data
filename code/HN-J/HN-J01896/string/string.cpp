#include<bits/stdc++.h>
using namespace std;
string s[100000000];
int main(){
	freopen("string.in","r",stin);
	freopen("sting.out","w",stout);
	int n,p=1,ans=0;
	for(int i=1;i<=n;i++){
		int m;
		cin>>m;
		char a;
		cin>>a;
		for(int j=p;j<=m;j++)s[j]=a;
		p=m;
		ans+=p;
	}
	if(ans%2==0){
		int y=1;
		for(int i=1;i<=ans/2;i++){
			if(s[i]!=s[ans-i+1])y=0;
		}
		if(y==1){
			cout<<0;
			return 0;
		}
	}
	else {
		int y=1;
		for(int i=1;i<=ans-1/2;i++){
			if(s[i]!=s[ans-i+1])y=0;
		}
		if(y==1){
			cout<<0;
			return 0;
		}
	}
	return 0;
}
