#include <bits/stdc++.h>
using namespace std;
string c1,c2;
char s1[3],s2[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1;
	for(int i=1;i<=3;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=1;i<=3;i++){
		cin>>s2[i];
	}
    if(c1!=c2){
	    cout<<"0000";
	    return 0;
    }
    cout<<"1";
    for(int i=1;i<=2;i++){
    	if(s1[i]!=s2[i]){
    		cout<<"000";
    		return 0;
		}
	}
	cout<<"1";
	if(s1[3]=='A'&&s2[3]=='B'||s1[3]=='A'&&s2[3]=='C'||s1[3]=='B'&&s2[3]=='A'||s1[3]=='B'&&s2[3]=='C'||s1[3]=='C'&&s2[3]=='B'||s1[3]=='C'&&s2[3]=='A') cout<<"1";
    else if(s1[3]=='D'&&s2[3]=='E'||s1[3]=='E'&&s2[3]=='D') cout<<"1";
    else{
    	cout<<"00";
    	return 0;
	}
    
	if(s1[3]=='A'&&s2[3]=='B'||s1[3]=='B'&&s2[3]=='C'||s1[3]=='D'&&s2[3]=='F'||s2[3]=='A'&&s1[3]=='B'||s2[3]=='B'&&s1[3]=='C'||s2[3]=='D'&&s1[3]=='F') cout<<"1";
	else cout<<"0";
	return 0;
}
