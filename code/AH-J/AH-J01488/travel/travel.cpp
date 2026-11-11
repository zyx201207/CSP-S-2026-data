#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a,a1,b,b1;
	cin>>a>>a1>>b>>b1;
	if(a==b){
		cout<<'1';
		if(a1.substr(0,2)==b1.substr(0,2)){
			cout<<'1';
			string s1=a1.substr(2,1),s2=b1.substr(2,1);
			if(((s1<="C"&&s1>="A")&&(s2<="C"&&s2>="A"))||((s1<="F"&&s1>="D")&&(s2<="F"&&s2>="D"))){
				cout<<'1';
				if((s1=="A"&&s2=="B")||(s1=="B"&&s2=="A")||(s1=="B"&&s2=="C")||(s1=="C"&&s2=="B")||(s1=="D"&&s2=="F")||(s1=="F"&&s2=="D"))
					cout<<'1';
				else cout<<'0';
				
			}
			else{
				cout<<"00";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
