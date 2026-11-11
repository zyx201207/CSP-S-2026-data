#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2; 
map<char,bool>vis;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0); 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	vis['A']=1;
	vis['B']=1;
	vis['C']=1;
	vis['D']=0;
	vis['F']=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		string a1="",a2="";
		a1+=s1[0];
		a1+=s1[1];
		a2+=s2[0];
		a2+=s2[1];
		if(a1==a2){
			cout<<1;
			if(vis[s1[2]]==vis[s2[2]]){
				cout<<1;
				if(abs(s1[2]-s2[2])==1){
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
