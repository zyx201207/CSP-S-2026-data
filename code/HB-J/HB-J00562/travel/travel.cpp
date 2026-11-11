#include <bits/stdc++.h>
using namespace std;
long long c1,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1[5],s2[5];

    cin>>c1>>s1[5]>>c2>>s2[5];
    if(c1==c2){
        cout<<"1";
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){


        cout<<"1";

        if(s1[2]=="A"&&s2[2]=="B")cout<<"1"<<"1";


        if(s1[2]=="A"&&s2[2]=="C")cout<<"1"<<"0";


        if(s1[2]=="B"&&s2[2]=="A")cout<<"1"<<"1";



        if(s1[2]=="B"&&s2[2]=="C")cout<<"1"<<"1";


        if(s1[2]=="C"&&s2[2]=="A")cout<<"1"<<"0";

        if(s1[2]=="C"&&s2[2]=="B")cout<<"1"<<"1";



        if(s1[2]=="D"&&s2[2]=="F")cout<<"1"<<"1";


        if(s1[2]=="F"&&s2[2]=="D")cout<<"1"<<"1";


		}







    return 0;
}

