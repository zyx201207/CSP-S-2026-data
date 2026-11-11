#include<bits/stdc++.h>
using namespace std;
string c1,c2;
string s1,s2;
map<char,int>mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int a=(c1[0]-'0')*10+c1[1]-'0';
	int b=(c2[0]-'0')*10+c2[1]-'0';
	int x=(s1[0]-'0')*10+s1[1]-'0';
	int y=(s2[0]-'0')*10+s2[1]-'0';
	char p=s1[2],q=s2[2];
	mp['A']=mp['B']=mp['C']=1;
	if(a==b){
		cout<<1;
		if(x==y){
			cout<<1;
			if(mp[p]==mp[q]){
				cout<<1;
				if(mp[p]==1){
					if(abs(p-q)==1){
						cout<<1;
					}else{
						cout<<0;
					}
				}else{
					cout<<1;
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
