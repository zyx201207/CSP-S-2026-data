//GZ-J00522 贵州省兴义市弘毅中学 骆奇凡 
#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	string a,b;
	int cnt=0;
	for(int i=0;i<5;i++)cin>>a[i];
	for(int i=0;i<5;i++)cin>>b[i];
	if(a[4]-'0'>b[4]-'0'){
	char k=a[4];
	a[4]=b[4];
	b[4]=k;}
	if(a[0]!=b[0]||a[1]!=b[1]){
	cout<<0<<0<<0<<0;
	}else{
	cout<<1;
	if(a[2]!=b[2]||a[3]!=b[3]){
	cout<<0<<0<<0;}else{
	cout<<1;
	if(b[4]-'0'-(a[4]-'0')==1&&b[4]!='A'&&b[4]!='D'){cout<<1<<1;
	}else if(b[4]='C'&&a[4]=='A'){cout<<1<<0;
	}else{cout<<0<<0;}}
	}
	return 0;
}
