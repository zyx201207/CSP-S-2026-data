//GZ-J00212 遵义市第一初级中学 杨铠溢 
#include <bits/stdc++.h>
using namespace std;
string s,a,b,c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>a>>b>>c;
	long long f=0,l=0,p=0,o=0;
	if(s==b){
		f=1;
	}
	if(f==1&&a[0]==c[0]&&a[1]==c[1]){
		l=1;
	}
	if(f==1&&l==1&&a[2]<='C'&&a[2]>='A'&&c[2]<='C'&&c[2]>='A'){
		p=1;
	}else if(f==1&&l==1&&a[2]<='F'&&a[2]>='D'&&c[2]<='F'&&c[2]>='D'){
		p=1;
	}
	if(f==1&&l==1&&p==1&&int(a[2]-c[2])==1){
		o=1;
	}else if(f==1&&l==1&&p==1&&int(c[2]-a[2])==1){
		o=1;
	}
	cout<<f<<l<<p<<o;
	return 0;
} 
