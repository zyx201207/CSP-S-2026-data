#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
bool f1,f2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c1>>s1>>c2>>s2;
	if((s1[2]-'A'+1)>3) f1=true;
	if((s2[2]-'A'+1)>3) f2=true;
	
	//1
	if(c1==c2){
		cout<<1;
		//2
		if((s1[0]==s2[0]) && (s1[1]==s2[1])){
			cout<<1;
			//3
			if(f1==f2){
				cout<<1;
				//4
				if(abs( (s2[2]-'A'+1) - (s1[2]-'A'+1) ) == 1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
		
	return 0;
}
