#include<bits/stdc++.h>
using namespace std;

int f[4];
string c1,s1,c2,s2;

void fun(){
	if(c1[0]!=c2[0]||c1[1]!=c2[1])return;
	f[0]=1;
	if(s1[0]!=s2[0]||s1[1]!=s2[1])return;
	f[1]=1;
	if((s1[2]<='C'&&s2[2]>='D')||(s1[2]>='D'&&s2[2]<='C'))return;
	f[2]=1;
	if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1)f[3]=1;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	fun();
	for(int i=0;i<4;i++){
		cout<<f[i];
	}
}
