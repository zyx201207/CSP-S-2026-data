#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	
	string c1,s1_1,c2,s2_1,s1_2,s2_2;
	cin>>c1>>s1_1>>s1_2>>c2>>s2_1>>s2_2;
	if(c1==c2){
		cout<<1;
		if(s1_1==s2_1)
		{
			cout<<1;
			if(s1_2=='A'&&s2_2=='B'||s2_2=='C'||s1_2=='B'&&s2_2=='A'||s2_2=='C'||s1_2=='C'&&s2_2=='B'||s2_2=='A'){
				cout<<1;
				if(((s1_2=='A')&&(s2_2=='B'))||((s1_2=='B')&&((s2_2=='A')||(s2_2=='C')))||((s1_2=='C')&&(s2_2=='B')))
					cout<<1;
			}else{
				if(((s1_2=='D')&&(s2_2=='F'))||((s1_2=='C')&&(s2_2=='D'))){
				cout<<1;
				if(((s1_2=='D')&&(s2_2=='F'))||((s1_2=='F')&&(s2_2=='D')))cout<<1;
			}	
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
} 
