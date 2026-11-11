#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int x1,x2,x3,x4;
map<char,int> mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	x1=c1[0]-'0';
	x2=c1[1]-'0';
	x3=c2[0]-'0';
	x4=c2[1]-'0';
	int sum1=x1*10+x2,sum2=x3*10+x4;
	if(sum1==sum2){
		cout<<"1";
		x1=s1[0]-'0';
		x2=s1[1]-'0';
		x3=s2[0]-'0';
		x4=s2[1]-'0';
		int sum3=x1*10+x2,sum4=x3*10+x4;
		if(sum3==sum4){
			cout<<"1";
			mp['A']=1;
			mp['B']=1;
			mp['C']=1;
			mp['D']=2;
			mp['F']=2;
			if(mp[s1[2]]==mp[s2[2]]){
				cout<<"1";
				if(char(s1[2]+1)==s2[2]||char(s1[2]-1)==s2[2]) cout<<"1";
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	
return 0;
}
