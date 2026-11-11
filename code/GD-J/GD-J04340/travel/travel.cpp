#include<iostream>
#include<string> 
using namespace std;
int judge(char a,char b)
{
	char c=max((int)a,(int)b);
	char d=min((int)a,(int)b);
	if(c-d==1 and (c=='D')) return 0;
	if(c-d==1 or (c=='F' and d=='D')) return 11;
	if(c-d==2 and c=='C') return 10;
	else return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	bool b1=false,b2=false;
	int ans;
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1) b1=true;
	else b1=false;
	if(b1 and c2[0]+c2[1]==s2[0]+s2[1]) b2=true;
	else b2=false;
	cout<<b1<<b2;
	if(b2)
	{
		ans=judge(c2[2],s2[2]);
		if(ans==0) cout<<"00";
		else cout<<ans;
	}
	else cout<<"00";
	return 0;
}
