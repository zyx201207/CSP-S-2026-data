#include<bits/stdc++.h>
using namespace std;
int main(){
	int c1,c2;
    int num;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
				cout<<"1";
				if(int(s1[2])==65||int(s1[2])==66||int(s1[2])==67){
					if(int(s2[2])==65||int(s2[2])==66||int(s2[2])==67){
						cout<<"1";
						if(int(s1[2]-s2[2])==1||int(s1[2]-s2[2])==-1){
							cout<<"1";
							num+=1;
							
						}
					}
					num+=1;
				}
				else if(int(s1[2])==68||int(s1[2])==70){
					if(int(s2[2])==68||int(s2[2])==70){
						cout<<"11";
						
					}
					num+=2;
				}
				num+=1;
			
		}
		num+=1;
	}
	for(int i=4-num;i>0;i--){
		cout<<"0";
	}
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	return 0;
}
