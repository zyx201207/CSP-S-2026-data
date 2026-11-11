#include<bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
bool pd1(string a,string b){
	return a[0]==b[0]&&a[1]==b[1];
}
bool pd2(string a,string b){
	int x=a[2]-'A';
	int y=b[2]-'A';
	if(x<3&&y<3)return true;
	else if(x>=3&&y>=3)return true;
	return false;
}
bool pd3(string a,string b){
	int x=a[2]-'A';
	int y=b[2]-'A';
    if(x>=3&&y>=3)return true;
    else if(x-y==1||y-x==1)return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(pd1(s1,s2)){
			cout<<"1";
			if(pd2(s1,s2)){
			   cout<<"1";
			   if(pd3(s1,s2)){
			   	  cout<<"1";
			   }
			   else cout<<"0";	
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
	else cout<<"0000";
	return 0;
}
