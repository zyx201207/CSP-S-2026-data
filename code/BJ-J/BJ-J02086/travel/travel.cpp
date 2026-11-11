#include <bits/stdc++.h>
using namespace std;
int main(){

string c1,c2,c3,c4;
cin>>c1>>c2>>c3>>c4;
if(c1==c3){cout<<"1";}
else
{cout<<"0000";}

if(c2=='A'&&c4=='B'||c2=='A'&&c4=='C'||c2=='B'&&c4=='A'||c2=='B'&&c4=='C'||c2=='C'&&c4=='B'||c2=='C'&&c4=='A'||c2=='D'&&c4=='E'||c2=='E'&&c4=='D')
{cout<<"1";
}

return 0;
}