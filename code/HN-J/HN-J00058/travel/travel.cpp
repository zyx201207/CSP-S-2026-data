#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;

	//同一车厢 
	if(c1==c2){
		cout<<1;
		//前两位：同一排 
		string row1=s1.substr(0,1);
		string row2=s2.substr(0,1);
		if(row1 == row2){
			cout<<1;
			//同侧：DF 
			if((s1[2]=='D' || s2[2]=='D') && (s1[2]=='F' || s2[2]=='F')){
				cout<<1<<1;
				
			}else if(s1[2]=='D' || s2[2]=='D' || s1[2]=='F' || s2[2]=='F'){
				//DF only one:
				cout<<0<<0;
			
			}else{
				cout<<1;
				if(s1[2]=='B' || s2[2]=='B'){
					cout<<1;
		
				}else{
					cout<<0;
		
				}
			}
			
		}else{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}

	return 0;
}

