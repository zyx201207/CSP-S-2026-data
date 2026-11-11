#include<bits/stdc++.h>
using namespace std;
string c2,c4,c1,c3;
int cnt,b,n;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stout);
	cin>>c1>>c2>>c3>>c4;
	if((c2[2]-'0'==c3[2]-'0'-1 ) or(c2[2]-'0'==c3[2]-'0'+1) ){
			cout<<1;
	}
	for(int i=0;i<2;i++)
	{
		if(c1[i]==c3[i])
		{
			cnt++;
		}
		if(c2[i]==c4[i])
		{
			b++;
		}
	}
	if(cnt==2) cout<<1;
	if(cnt==0 or cnt==1){ 
		cout<<"0000";
		return 0;
	}
	if(b!=2){ 
		cout<<"000";
		return 0;
	}
	if(b==2) cout<<1;
	if((c2[2]-'0'==c3[2]-'0'-1 ) or(c2[2]-'0'==c3[2]-'0'+1) ){
		cout<<"11";
	}
	if((c2[2]-'0'!=c3[2]-'0'-1 ) or(c2[2]-'0'!=c3[2]-'0'+1) ){
		cout<<"10";
	}                           
	return 0;
	
}
