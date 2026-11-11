 #include<bits/stdc++.h>
 using namespace std;
 int main(){
 	//freopen("travel.in","r",stdin);
 	//freopen("travel.out","w",stdout);
 	
 	string c1,s1,c2,s2;
 	cin>>c1>>s2>>c2>>s2;//input
 	
 	if(c1==c2)cout<<"1";//p1
 	else cout<<"0";
 	
 	if(s1!=s2 && c1==c2) cout<<"1";//p2
 	else cout<<"0";
 	
 
 	if(c1==c2 || s1==s2) cout<<"1";
    else cout<<"0";//p3
    
    
	if(c1==c2 && s2!=s1) cout<<"1";
	else cout<<"0";
	return 0;
	 
 } 
