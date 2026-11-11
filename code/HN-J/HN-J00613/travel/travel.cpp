#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	int c1=(x1[0]-'0')*10+(x1[1]-'0'),s1=(y1[0]-'0')*10+(y1[1]-'0'),c2=(x2[0]-'0')*10+(x2[1]-'0'),s2=(y2[0]-'0')*10+(y2[1]-'0');
	int pos1=y1[2]-'A'+1;
	if(y1[2]=='F')pos1--;
	int pos2=y2[2]-'A'+1;
	if(y2[2]=='F')pos2--;
	if(c1==c2)cout<<1;
	else cout<<0;
	if(c1==c2&&s1==s2)cout<<1;
	else cout<<0;
	if(c1==c2&&s1==s2&&((pos1<=3&&pos2<=3)||(pos1>=4&&pos2>=4)))cout<<1;
	else cout<<0;
	if(c1==c2&&s1==s2&&((pos1<=3&&pos2<=3)||(pos1>=4&&pos2>=4))&&abs(pos1-pos2)==1)cout<<1;
	else cout<<0;
	return 0;
} 
