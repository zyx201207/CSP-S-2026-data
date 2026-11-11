#include<iostream>
#include<map>
using namespace std;
map <char,int> m;
map<char,int> mapp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	m['A']=m['B']=m['C']=1;
	m['D']=m['F']=2;

	mapp['A']=1,mapp['B']=2,mapp['C']=3,mapp['D']=10103,mapp['F']=10104;
	
	string c1,c2,s1,s2;//c-> ее  s->ап
	cin>>c1>>s1>>c2>>s2;
	int flag1=(c1==c2);
	int flag2=(flag1&&(s1[0]==s2[0])&&(s1[1]==s2[1]));
	int flag3=(flag2&&(m[s1[2]]==m[s2[2]]));
	int flag4=(flag2 && (abs(mapp[s1[2]]-mapp[s2[2]]) == 1) );
	cout<<flag1<<flag2<<flag3<<flag4;
}
