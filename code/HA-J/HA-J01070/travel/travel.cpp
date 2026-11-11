#include<bits/stdc++.h>
using  namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
string c1,c2,s1,s2;
cin>>c1>>c2>>s1>>s2;
if(c1[0]>='1'&&c1[1]>='6'||c1[0]=='0'&&c1[1]=='1'||s1[0]=='0'&&s1[1]=='1'||s1[0]>='1'&&s1[1]>='6'){
	return 0;
}
if(c1[0]==s1[0]&&c1[1]==s1[1]){
    cout<<'1';
    }else{
	  cout<<'0';
}
    if(c1[0]==s1[0]&&c1[1]==s1[1]&&c2[0]==s2[0]&&c2[1]==s2[1]){
    cout<<'1';
    }else{
    cout<<'0';
   }
   if(c1[0]==s1[0]&&c1[1]==s1[1]){
   if(c2[0]==s2[0]&&c2[1]==s2[1]&&c2[2]=='A'&&s2[2]=='B'||c2[2]=='B'&&s2[2]=='A'||c2[2]=='C'&&s2[2]=='B'||c2[2]=='B'&&s2[2]=='C'||c2[2]=='A'&&s2[2]=='C'||c2[2]=='C'&&s2[2]=='A'||c2[2]=='D'&&s2[2]=='F'||c2[2]=='F'&&s2[2]=='D'){
    cout<<'1';
}else{
cout<<'0';
}
}
if(c1[0]==s1[0]&&c1[1]==s1[1]&&c2[0]==s2[0]&&c2[1]==s2[1]){
	if(c2[2]=='A'&&s2[2]=='B'||c2[2]=='B'&&s2[2]=='A'||c2[2]=='C'&&s2[2]=='B'||c2[2]=='B'&&s2[2]=='C'||c2[2]=='D'&&s2[2]=='F'||c2[2]=='F'&&s2[2]=='D'){
	 cout<<'1';
	}else{
cout<<'0';
}
}
	return 0;
}
