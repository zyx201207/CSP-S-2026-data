#include<bits/stdc++.h>
using namespace std;
int x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	cin>>x>>s1>>y>>s2;
	int p=int(s1[2]-'A'),q=int(s2[2]-'A');
	if(x!=y){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if((p<=2&&q<=2)||(p>=3&&q>=3)){
				cout<<1;
				if(p==q+1||p==q-1){
					cout<<1;
				}
				else{
					cout<<0;
					return 0;
				}
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
} 
