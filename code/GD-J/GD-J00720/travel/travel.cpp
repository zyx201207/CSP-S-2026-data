#include<bits/stdc++.h>
using namespace std;
bool is_abc(char c){
	return (c=='A'||c=='B'||c=='C');
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
		int pai_1=(s1[0]-'0')*10+(s1[1]-'0'),pai_2=(s2[0]-'0')*10+(s2[1]-'0');
		if(pai_1!=pai_2){
			cout<<"000";
			return 0;
		}else{
			cout<<1;
			char line_1=s1[2],line_2=s2[2];
			if(is_abc(line_1)!=is_abc(line_2)){
				cout<<"00";
				return 0;
			}else{
				cout<<1<<(abs((int)(line_1-line_2))==1);
			}
		}
	}
	return 0;
} 
