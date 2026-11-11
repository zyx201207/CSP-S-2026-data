#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int sum=0,sum1=0,sum2=0;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
	    cout<<"1";
	    for(int i=0;i<=2;i++){
		    if((s1[0]==s2[0]) and (s1[1]==s2[1])){
			    sum=1;
			    if(s1[2]=='A' and s2[2]=='B') sum1=1;
				else if(s1[2]=='A' and s2[2]=='C') sum1=1;
				else if(s1[2]=='B' and s2[2]=='A') sum1=1;
				else if(s1[2]=='B' and s2[2]=='C') sum1=1;
				else if(s1[2]=='C' and s2[2]=='A') sum1=1;
				else if(s1[2]=='C' and s2[2]=='B') sum1=1;
				else if(s1[2]=='D' and s2[2]=='F') sum1=1;
				else if(s1[2]=='F' and s2[2]=='D') sum1=1;
				else sum1=0;
				if(s1[2]=='A' and s2[2]=='B') sum2=1;
				else if(s1[2]=='B' and s2[2]=='A') sum2=1;
				else if(s1[2]=='B' and s2[2]=='C') sum2=1;
				else if(s1[2]=='C' and s2[2]=='B') sum2=1;
				else if(s1[2]=='D' and s2[2]=='F') sum2=1;
				else if(s1[2]=='F' and s2[2]=='D') sum2=1;
				else sum2=0;
			}
			else sum=0;
	    }
	    cout<<sum<<sum1<<sum2;
	}	
	else cout<<"0000";
	return 0;
}
