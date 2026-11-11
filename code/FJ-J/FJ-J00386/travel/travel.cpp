#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
int main() {
	freopen("travel","r",stdin);
	freopen("travel","w",stdout);
	
	cin>>s1>>c1>>s2>>c2;
	
	for(int i=0;i<=3;i++){
		if(s1==s2){
		cout<<1;
		if(s2[2]==c2[2]){
			cout<<1<<1;
			if(s2[1]+1==c2[1]||s2[1]-1==c2[1]){
				cout<<1;
			}
		}
	}
	else{
		cout <<0;
	}
	}
	
	
	return 0;
}
//老师求求您给点分 
