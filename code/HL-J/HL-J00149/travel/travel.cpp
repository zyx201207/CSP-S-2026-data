#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in" , "r" , stdin);
    freopen("travel.out" , "w" , stdout);
    string c1 , s1 , c2 , s2 , n1 , n2 , t1 , t2;
    cin>>c1>>s1>>c2>>s2;
    n1 += s1[0] + s1[1];
    n2 += s2[0] + s2[1];
    t1 = s1[2];
    t2 = s2[2];
    if(c1 == c2){
        cout<<"1";
        if(n1 == n2){
            cout<<"1";
        if(t1 =="A"&&t2=="B")
            cout<<"11";
        else if(t1 =="A" && t2=="C")
            cout<<"10";
        else if(t1 =="B" && t2=="A")
            cout<<"11";
        else if(t1 =="B" && t2=="C")
            cout<<"11";
        else if(t1 =="C" && t2=="A")
            cout<<"10";
        else if(t1 =="C" && t2=="B")
            cout<<"11";
        else if(t1 =="E" && t2=="F")
            cout<<"11";
        else if(t1 =="F" && t2=="E")
            cout<<"11";
        else
            cout<<"00";
    }
    else
        cout<<"000";
    }
    else
        cout<<"0000";
    return 0;
}
