#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int main(){
	string c1,s1,c2,s2;
	long long b[4];
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		b[0]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]) {
			b[1]=1;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				b[2]=1;
				if((int(s1[0])+int(s1[0])+1==int(s2[0])+int(s2[0]))||(int(s1[0])+int(s1[0])-1==int(s2[0])+int(s2[0]))) b[3]=1;
				else if(s1[2]+1==s2[2]||s1[2]-1==s2[2]) b[3]=1;
				else b[3]=0;
			}
			else for(int i=2;i<4;i++) b[i]=0;
		}
		else for(int i=1;i<4;i++) b[i]=0;
	}
		else {
			for(int i=0;i<4;i++) b[i]=0;
		}
	for(int i=0;i<4;i++) cout<<b[i];
}
