#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	char m,n;
	long long a,b,c=0,d=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
	    cout<<"1";
		a=(s1[0]-48)*10+(s1[1]-48);
		b=(s2[0]-48)*10+(s2[1]-48);	
		if(a==b){
			cout<<"1";
		    m=s1[2],n=s2[2];
		    if((int)m>=65&&(int)m<=67) c++;
		    if((int)n>=65&&(int)n<=67) c++;
		    if((int)m==68||(int)m==69) d++;
		    if((int)n==68||(int)n==69) d++;
		    if(c==2||d==2){
		    	cout<<"1";
			    if(abs(m-n)==1) cout<<"1";
			    else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
    return 0;
}

