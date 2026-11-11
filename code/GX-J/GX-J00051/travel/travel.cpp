#include <bits/stdc++.h>
using namespace std;
int a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	a[0]=1;
	int x=s1[2]-'0',y=s2[2]-'0';
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		a[1]=1;
	}
	if((s1[2]>='A'&& s1[2]<='C') && (s2[2]>='A'&& s2[2]<='C') && a[1]){
		a[2]=1;
	}else if((s1[2]>='D'&& s1[2]<='F') && (s2[2]>='D'&& s2[2]<='F') && a[1]){
		a[2]=1;
	}
	if(abs(x-y)==1 && a[2]){
		a[3]=1;
	}
	cout<<a[0]<<a[1]<<a[2]<<a[3];
    return 0;
}
