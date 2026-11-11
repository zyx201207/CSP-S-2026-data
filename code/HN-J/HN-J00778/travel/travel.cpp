#include<bits/stdc++.h> 

using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	int c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else if(c1!=c2){
		cout<<"0";
		}
		if(s1==s2||c1==c2){
			cout<<"0000";
		}
	else if(s1!=s2||c1==c2){
		cout<<"1100";
	}
	else if(s1!=s2||c1==c2)
	{
		cout<<"1111";
	}
    else  if(s1!=s2||c1==c2)
	{
    	cout<<"0000";
	}
	else
	{
		cout<<"1110";
	}
	
	return 0;
}                      
