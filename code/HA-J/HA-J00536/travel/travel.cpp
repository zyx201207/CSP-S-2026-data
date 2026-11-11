#include<bits/stdc++.h>
using namespace std;

int main(){
string s,s1,y1,y2,z;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s>>s1>>y1>>y2;
	if(s==y1){
		z=z+'1';
		if(s1[0]==y2[0]&&s1[1]==y2[1]){
			z=z+'1';
			if(s1[2]=='D'&&y2[2]=='F'||s1[2]=='F'&&y2[2]=='D'){
				cout<<"1111";
				return 0;
			}
			if(s1[2]>='A'&&s1[2]<='C'&&y2[2]>='A'&&y2[2]<='C'){
				z=z+'1';
				
				int a=int(s1[2]-'A');
				int b=int(y2[2]-'A');
				if(a-1==b||b-1==a)z+='1';
				else {
					cout<<"1110";
					return 0;
				}
				
				
			}else{
				cout<<"1100";
				return 0;
			}
		}else{
			cout<<"1000";
			return 0;
		} 
		
		
	}else{
		cout<<"0000";
		return 0;
	} 
	cout<<z;
	return 0;
	
}
