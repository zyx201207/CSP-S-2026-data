#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	int sp1=s1[2]-'A'+1;
	int sp2=s2[2]-'A'+1;
	int a=(s1[0]-48)*10+(s1[1]-48);
	int b=(s2[0]-48)*10+(s2[1]-48);
	if(c1==c2){
		if(a==b){
			if(sp1<=3&&sp2<=3){
				if(sp1+1==sp2||sp1-1==sp2){
					cout<<"1111";
				}
				else cout<<"1110";
			} 
			else if(sp1>=4&&sp2>=4){
				if(sp1+2==sp2||sp1-2==sp2){
					cout<<"1111";
				}
				else cout<<"1110";
		    }
		    else{
		    	cout<<"1100";
			}
		}
		else  cout<<"1000";
	}
	else  cout<<"0000";
	return 0;
}
