#include<bits/stdc++.h>
using namespace std;
int c1,c2;
bool f[5]={0};
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		f[1]=1;
		int a1=s1[0]*10+s1[1];
		int a2=s2[0]*10+s2[1];
		if(a1==a2){
			f[2]=1;
			char x=s1[2],y=s2[2];
			if((x<='C' && y<='C') || (x>='D' && y>='D')){
				f[3]=1;
				if(x+1==y || y+1==x) f[4]=1;
			}
		}
	}
	for(int i=1;i<=4;i++) cout<<f[i];
	return 0;
} 
