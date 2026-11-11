#include<bits/stdc++.h>
using namespace std;
int c_1,c_2,w1,w2;
char s_1,s_2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c_1>>w1>>s_1>>c_2>>w2>>s_2;
	if(c_1==c_2) 
	{
		cout<<1;
		if(w1==w2)
		{
			cout<<1;
			if(s_1<='C'&&s_2<='C'||s_1>='D'&&s_2>='D')
			{
				cout<<1;
				if(s_1==s_2+1||s_1==s_2-1)
				{
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
	     } 
	    else cout<<"000";
	}
	else cout<<"0000";
	//ÇóAC; 
	return 0;
} 
