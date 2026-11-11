#include<bits/stdc++.h>
using namespace std;
string a2,b2,a1,b1;
int main(){
freopen("travel.in","r",stdin);	
freopen("travel.out","w",stdout);	
cin>>a1;
cin>>a2;
cin>>b1;
cin>>b2;
if(a1==b1)cout<<1;
else cout<<0;

if(a2[0]==b2[0] && a2[1]==b2[1] && a1==b1)cout<<1;
else cout<<0;

if(a1==b1 && a2[0]==b2[0] && a2[1]==b2[1] && int(a2[2]-'A'+1)<=3 && int(b2[2]-'A'+1)<=3 || int(a2[2]-'A'+1)>3 && int(b2[2]-'A'+1)>3 && a2[0]==b2[0] && a2[1]==b2[1] && a1==b1)cout<<1;
else cout<<0;

if(a1==b1 && a2[0]==b2[0] && a2[1]==b2[1] && abs(int(a2[2]-'A'+1)<=3-int(b2[2]-'A'+1)) && int(a2[2]-'A'+1)<=3 && int(b2[2]-'A'+1)<=3 || int(a2[2]-'A'+1)>3 && int(b2[2]-'A'+1)>3 && a2[0]==b2[0] && a2[1]==b2[1] && a1==b1)cout<<1;
else cout<<0;
fclose(stdin);
fclose(stdout);
return 0;
}
