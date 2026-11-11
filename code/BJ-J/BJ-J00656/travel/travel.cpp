#include<bits/stdc++.h>
using namespace std;
string n1,n2,m1,m2;
int q1=0,q2=0,q3=0,q4=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n1>>n2>>m1>>m2;
    if(n1==m1){
        q1=1;
    }
    else{
        q1=q2=q3=q4=0;
        cout<<q1<<q2<<q3<<q4;
        return 0;
    }
    for(int i=0;i<=1;i++){
        if(n2[i]!=m2[i]){
            q2=q3=q4=0;
            cout<<q1<<q2<<q3<<q4;
            return 0;
        }
    }
    q2=1;
    if(max(n2[2],m2[2])=='D'&&min(n2[2],m2[2])=='F'){
        q3=q4=1;
    }
    else if(max(n2[2],m2[2])=='C'&&min(n2[2],m2[2])=='B'||max(n2[2],m2[2])=='B'&&min(n2[2],m2[2])=='A'){
        q3=q4=1;
    }
    else if(max(n2[2],m2[2])=='C'&&min(n2[2],m2[2])=='A'){
        q3=1;
        q4=0;
    }
    else{
        q3=q4=0;
    }
    cout<<q1<<q2<<q3<<q4;
    return 0;
}
