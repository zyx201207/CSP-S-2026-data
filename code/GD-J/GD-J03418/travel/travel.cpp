#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

bool pd(char a,char b){
	if(a<'D' && b<'D') return true;
	else if(a>'D' && b>'D') return true;
	else return false ;
}

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2; 
	
	if(c1==c2) {
		cout<<1;
		int g1,g2;
	    g1=(s1[0]-'0')*10+(s1[1]-'0');
        g2=(s2[0]-'0')*10+(s2[1]-'0');
	    if(g1==g2) {
	        cout<<1;
	        
	        if(pd(s1[2],s2[2])){
	        	cout<<1;
	        	if(s1[2]-'0'+1==s2[2]-'0' || s1[2]-'0'-1==s2[2]-'0') {
	        	    cout<<1;
				}
				else cout<<"0";
			}
	        else cout<<"00";
		}
	    else cout<<"000";
	    
	}
	else cout<<"0000";
	
	
	return 0;
}
