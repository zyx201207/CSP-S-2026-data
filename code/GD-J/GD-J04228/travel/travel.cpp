#include<bits/stdc++.h>
using namespace std;
string x,y,xa,ya; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	map<char,int> mp;
	mp['A']=mp['B']=mp['C']=1;
	mp['D']=mp['F']=2;
	cin>>x>>y>>xa>>ya;
	if(x==xa){
		cout<<1;
		if(y[0]==ya[0]&&y[1]==ya[1]){
			cout<<1;
			if(mp[y[2]]==mp[ya[2]]){
				cout<<1;
				if(mp[y[2]]==2){
					cout<<1;
					return 0;
				}
				else{
					if(abs(int(y[2])-int(ya[2]))==1){
						cout<<1;
						return 0;
					}
					else{
						cout<<'0';
						return 0; 
					}
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
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
} 
