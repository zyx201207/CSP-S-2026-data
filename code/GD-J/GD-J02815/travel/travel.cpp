#include<bits/stdc++.h>
using namespace std;

string cl,sl,cr,sr;
int zt[5];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>cl>>sl>>cr>>sr;
	
	if(cl==cr)zt[1]=1;
	else zt[1]=0;
	if((sl[0]==sr[0]&&sl[1]==sr[1])&&zt[1]==1)zt[2]=1;
	else zt[2]=0;
	if(((sl[2]<='C'&&sr[2]<='C')||(sl[2]>='D'&&sr[2]>='D'))&&zt[1]==1&&zt[2]==1)zt[3]=1;
	else zt[3]=0;
	if((sl[2]-sr[2]==1||sl[2]-sr[2]==-1)&&(zt[3]==1&&zt[2]==1&&zt[1]==1)){
		zt[4]=1;
	}
	else zt[4]=0;
	
	for(int i=1;i<=4;i++)cout<<zt[i];
	
	return 0;
}
