#include<iostream>
#include<string>
using namespace std;

int c1,c2;
string s1,s2;
bool f[4]={0,1,0,0};
bool g[5]={0,0,0,1,1};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	f[0]=c1==c2;
	for(int i=0;i<2;++i)
		if(s1[i]!=s2[i])
			f[1]=0;
	if(!f[0])
		f[1]=0;
	if(f[1])
		f[2]=g[s1[2]-'A']==g[s2[2]-'A'];
	if(f[2])
		if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1)
			f[3]=1;
	for(int i=0;i<4;++i)
		cout<<f[i];
		
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
