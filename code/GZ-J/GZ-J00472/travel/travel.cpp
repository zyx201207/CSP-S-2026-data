//GZ-J00472 遵义市第十九中学刘泽熙
#include<bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
int a[4]={0};
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]) a[1]=1;
	if(a[1]==1){
		if(s1[0]==s2[0]&&s1[1]==s2[1]) a[2]=1;
	}else{
		a[2]=0;
	}
	if(a[2]==1){
		if(s1[2]>'C'&&s2[2]>'C') a[3]=1;
		if(s1[2]<='C'&&s2[2]<='C') a[3]=1;
	}else{
		a[3]=0;
	}
	if(a[3]==1){
		if(s1[2]=='A'&&s2[2]=='B') a[4]=1;
		if(s1[2]=='B'&&s2[2]=='C') a[4]=1;
		if(s1[2]=='C'&&s2[2]=='B') a[4]=1;
		if(s1[2]=='D'&&s2[2]=='F') a[4]=1;
		if(s1[2]=='F'&&s2[2]=='D') a[4]=1;
	}else{
		a[4]=0;
	}
	cout<<a[1]<<a[2]<<a[3]<<a[4];
}
