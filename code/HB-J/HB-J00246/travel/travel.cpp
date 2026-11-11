#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int cnt=0;
	if(c1==c2)
	{
		cout<<1;
		cnt++;
		if(s1[0]==s2[0] && s1[1]==s2[1])
		{
			cout<<1;
			cnt++;
			if((s1[2]<='C' && s2[2]<='C')||(s1[2]>='D' && s2[2]>='D'))
			{
				cout<<1;
				cnt++;
				if(s1[2]>='D' && s2[2]>='D')
				{
					cout<<1;
					cnt++;
				}
				if((s1[2]=='A' && s2[2]=='C') || (s2[2]=='A' && s1[2]=='C')){
					cnt+=0;
				}
				else
				{
					cout<<1;
					cnt++;
				}
				
			}
		}
	}
	if(cnt<4)
	for(int i=0;i<4-cnt;i++)
		cout<<0;
	return 0;
}
