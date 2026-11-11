#include<bits/stdc++.h>

using namespace std;
main(){
	freopen("travel1.in","r",stdin);
	//freopen("travel.ans1","w",stdout);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char a=s1[2],b=s2[2];
	cout<<s1<<s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			
			if(s1[2]>s2[2]){
				swap(s1[2],s2[2]); 
			}
			
			if(s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C')){
				cout<<"1";
				if(s1[2]=='A'&&s2[2]=='C'){
					cout<<"0";
				}
				else{
					cout<<"1";
				}
			}
			else if(s1[2]=='D'&&s2[2]=='F'){
				cout<<"11";
			}
			else
				cout<<"00";
	    }
		else
		    cout<<"000";
	}
	else
		cout<<"0000";
}
 
