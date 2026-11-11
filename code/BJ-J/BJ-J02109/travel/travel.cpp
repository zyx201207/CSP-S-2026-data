#include<bits/stdc++.h>
using namespace std;

string c1,c2,s1,s2;
int a[5];

int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        a[1]=1;
    }
    else{
        a[1]=0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        a[2]=1;
    }
    else{
        a[2]=0;
    }
    if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'||s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
        a[3]=1;
    }
    else{
        a[3]=0;
    }
    int a1=s1[2]-'A';
    int b1=s2[2]-'A';
    if(a1-b1==1||b1-a1==1){
        a[4]=1;
    }
    else{
        a[4]=0;
    }
    for(int i=1;i<=4;++i){
        if(a[i-1]==0&&i!=1){
            a[i]=0;
        }
        cout<<a[i];
    }

    return 0;
}
