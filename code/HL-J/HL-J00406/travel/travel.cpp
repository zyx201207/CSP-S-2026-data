#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen(travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int len=s1.size();
    int len2=s2.size();
    if(c1==c2){
    	cout<<"1";
    	for(int i=1;i<=len;i++){
    		if(i==1){
    			if(s1[i]!=s2[i]){
    			cout<<"000";
    			break;
				}
			}
			if(i==2){
    			if(s1[i]==s2[i]){
    			cout<<"1";
				}
			}
			if(i==3){
				if(s1[i]=='A'&&s2[i]=='B'||s1[i]=='A'&&s2[i]=='C'||s1[i]=='B'&&s2[i]=='C'||s2[i]=='A'&&s1[i]=='B'||s2[i]=='A'&&s1[i]=='C'||s2[i]=='B'&&s1[i]=='C'){
					cout<<"1";
					if(s1[i]=='A'&&s2[i]=='B'||s1[i]=='B'&&s2[i]=='C'||s1[i]=='C'&&s2[i]=='B'||s1[i]=='B'&&s2[i]=='A'){
						cout<<"1";
					}
					else cout<<"0";
					break;
				}
				if(s1[i]=='D'&&s2[i]=='F'||s2[i]=='D'&&s1[i]=='F'){
					cout<<"11";
					break;
				}
				else cout<<"00";
				break;
			}
			else cout<<"000";
			break;
		}
	}
	else cout<<"0000";
    return 0;
}
