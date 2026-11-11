#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		
		int s_1=s1[0]*10+s1[1];
		int s_2=s2[0]*10+s2[1];
		if(s_1==s_2){
			cout<<1;
			
			char s__1=s1[2];
			char s__2=s2[2];
			if((s__1<='C'&&s__2>='D')||(s__2<='C'&&s__1>='D')){
				cout<<"00";
			}
			else{
				cout<<1;
				
				if((s__1-'A'+1==s__2-'A'||s__2-'A'+1==s__1-'A') && (s__1!='C'&&s__2!='D')&&(s__2!='C'&&s__1!='D') ){
					cout<<1;
				}
				else{
					cout<<"0";
				}	
			}		
		}
		else{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
 } 
