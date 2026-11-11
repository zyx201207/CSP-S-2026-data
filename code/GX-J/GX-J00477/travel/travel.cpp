#include <bits/stdc++.h>
using namespace std;

freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string c1,c2,s1,s2;
int main(){
    cin>>c1>>s1>>c2>>s2;
if (c1 == c2){
    cout<<"1";
}
else{
    cout<<"0";
}
if (c1[0] == c2[0] || c1[1] == c2[1]){
    cout<<"1";
}
else{
    cout<<"0";
}
if(c1[2]=="A"||c1[2]=="B"||c1[2]=="C"){
    if(c2[2]=="A"||c2[2]=="B"||c2[2]=="C"){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
}
else if(c1[2]=="D"||c1[2]=="E"){
    if(c2[2]=="D"||c2[2]=="E"){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
}
if(c1[2]=="A"){
    if(c2[2]=="B"){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
}
else if(c1[2]=="B"){
    if(c2[2]=="A"||c2[2]=="C"){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
}
else if(c1[2]=="C"){
    if(c2[2]=="B"){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
}
else if(c1[2]=="D"){
    if(c2[2]=="E"){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
}
else if(c1[2]=="E"){
    if(c2[2]=="D"){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
}
return 0;
}
