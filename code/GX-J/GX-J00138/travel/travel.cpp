#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,c1,c2;
    cin>>s1>>c1;
    cin>>s2>>c2;
    if(c1==c2){
        cout<<"1";
    }else{
        cout<<"0";
        cout<<"0";
        cout<<"0";
        cout<<"0";
        return 0;
    }
    char a1=s1[2];
    char a2=s2[2];
    if(a1=='A'&&a2=='B'||a2=='A'&&a1=='B'){
        cout<<"1";
        cout<<"1";
        cout<<"1";
    }else if(a1=='C'&&a2=='B'||a2=='C'&&a1=='B'){
        cout<<"1";
        cout<<"1";
        cout<<"1";
    }else if(a1=='D'&&a2=='F'||a2=='D'&&a1=='F'){
        cout<<"1";
        cout<<"1";
        cout<<"1";
    }else{
        if(a1=='A'&&a2=='B'||a1=='A'&&a2=='C'){
            cout<<"1";
            cout<<"1";
        }else if(a2=='A'&&a1=='B'||a2=='A'&&a1=='C'){
            cout<<"1";
            cout<<"1";
        }
        cout<<"0";
    }


    return 0;
}

