#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int t=0;
char a1,a2; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0] && c1[1]==c2[1]){
		cout<<"1";
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<"1";
			if(s1[2]=='A' || s1[2]=='B' || s1[2]=='C') 
			    if(s2[2]=='D') cout<<"00";
			    else if(s2[2]=='F') cout<<"00";
			    else{
			    	t=1;
			    	cout<<"1";
				}
			else if(s1[2]=='D')
			    if(s2[2]!='F') cout<<"00";
			    else cout<<"11";
			else if(s1[2]=='F')
			    if(s2[2]!='D') cout<<"00";
			    else cout<<"11";
			if(t==1){
				a1=s1[2];
				a2=s2[2];
				if(a2-a1==1 || a1-a2==1)
				    cout<<"1";
				else cout<<"0";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
