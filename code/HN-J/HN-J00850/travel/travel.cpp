#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	int c1,c2;
	
	cin>>c1>>s1>>c2>>s2;
	
	int y1=int(s1[0]-'0')*10+int(s1[1]-'0');
	int y2=int(s2[0]-'0')*10+int(s2[1]-'0');
	
	int x1=int(s1[2]-'A'+1);
	int x2=int(s2[2]-'A'+1);
	
	if(c1==c2){
		//cout<<"1";
		if(y1==y2){
			//cout<<"1";
			if((x1<=3&&x2<=3)||(x1>=4&&x2>=4)){
				//cout<<"1";
				if(abs(x1-x2)==1||x1==4&&x2==6||x2==4&&x1==6){
					cout<<"1111";
				}
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	cout<<endl;
	return 0;
}
