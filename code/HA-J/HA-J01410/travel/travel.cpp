#include <bits/stdc++.h>
using namespace std;

string rn,rs,xn,xs;
int c1[10],c2[10],s1[10],s2[10];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rn>>rs>>xn>>xs;
	for(int i=0;i<rn.size();i++){;
		c1[i]=rn[i]-'0';}
	for(int i=0;i<xn.size();i++){
		s1[i]=xn[i]-'0';}
	for(int i=0;i<rs.size();i++){;
		c2[i]=rs[i]-'0';}
	for(int i=0;i<xs.size();i++){
		s2[i]=xs[i]-'0';}
	int flag=0;
	//是否在同一车厢 
	for(int i=0;i<rn.size();i++){
		if(c1[i]==s1[i]){
			flag++;
		}
	}
	if(flag==rn.size()){
		cout<<"1";
		//同一排 
		flag=0;
		for(int i=0;i<rs.size()-1;i++){
			if(c2[i]==s2[i]){
			flag++;
			}
		}
		if(flag==rs.size()-1){
			cout<<"1";
			//同一侧 
			if((c2[2]<='C'-'0'&&c2[2]>='A'-'0') && (s2[2]<='C'-'0'&&s2[2]>='A'-'0')){
				cout<<"1";
				//相邻 
				if((c2[2]+1==s2[2] || c2[2]-1==s2[2])){
					cout<<"1";
					return 0;
				}
				else{
					cout<<"0";
				}
			}
			else if((c2[2]>='D'-'0'&&c2[2]<='F'-'0') && (s2[2]>='D'-'0'&&s2[2]<='F'-'0')){
				cout<<"11";
				return 0;
			}
			else{cout<<"00";}
		}
		else{cout<<"000";}
	}
	else{cout<<"0000";}
	
	flag=0;
	
	
//	cout<<c1;
	
	return 0;
}
