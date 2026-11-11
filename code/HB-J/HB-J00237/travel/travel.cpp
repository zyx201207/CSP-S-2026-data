#include <bits/stdc++.h>
using namespace std;
string c_1,s_1,c_2,s_2;
map <char,int> mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1>>s_1>>c_2>>s_2;
	mp['A']=1;
	mp['B']=1;
	mp['C']=1;
	mp['D']=2;
	mp['F']=2;
	if(c_1==c_2)	
	{
		cout<<1;
		if((s_1[0]-'0')*10+(s_1[1]-'0')==(s_2[0]-'0')*10+(s_2[1]-'0')){
			cout<<1;
			if(mp[s_1[2]]==mp[s_2[2]]){
				cout<<1;
				if(((int)s_1[2]+1==(int)s_2[2]&&s_1[2]!='c')||((int)s_1[2]-1==(int)s_2[2]&&s_1[2]!='D')){
						cout<<1;
				}
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
