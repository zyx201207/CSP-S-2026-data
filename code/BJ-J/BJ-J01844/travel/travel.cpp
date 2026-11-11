#include<bits/stdc++.h>
using namespace std;
int c1,c2,flag=0;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
    }
    else{
        cout<<0;
    }
    int x=s1[2],y=s2[2];
    int m[5],n[5];

    for(int i=0;i<=1;i++){
        m[i]=s1[i]-'0';
        n[i]=s2[i]-'0';
    }
    if(m[1]==n[1]&&m[0]==n[0]){
        cout<<1;
    }
    else{
        cout<<0;
    }
    int a,b;
    a=x-'A'+1;
    b=y-'A'+1;
    if(a==4&&b==6||(a<=3&&b<=3)){
        cout<<1;
    }
    else{
        cout<<0;
    }
    if((a==4&&b==6)||(a==6&&b==4)){
        cout<<1;
    }
    else if((a<=3&&b<=3)&&(a-b==1||b-a==1)){
        cout<<1;
    }
    else{
        cout<<0;
    }
    cout<<endl;
    return 0;
}
//02 01A 02 01B
