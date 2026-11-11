#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,x,y;
int v[4]={0,0,0,0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	x=s2[0]+s2[1];
	y=s4[0]+s4[1];
	if(s1==s3){
		v[0]=1;
		if(x==y){
			v[1]=1;
			if((s2[2]<='C'&&s4[2]<='C')||(s2[2]>='D'&&s4[2]>='D')){
				v[2]=1;
				if(abs(int(s2[2]-s4[2]))==1)v[3]=1;
			}
		}
	}
	for(int i=0;i<4;i++)cout<<v[i];
	return 0;
}
