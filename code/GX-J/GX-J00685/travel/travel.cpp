#include <bits/stdc++.h>
using namespace std;

int main(){
freopen ("travel.in","r,"stdin);
freopen("travel.out","w",stdout);
int c1=0,c2=0;
string s1,s2;
cin>>c1>>s1>>c2>>s2;
if(c1==c2){
    cout<<1;
}
else{
    cout<<0;
}
cout<<1;
for(int i=0;i<18;i++){
    string s11,s22;
    int j=i+1;
    s11=j+'C';
    s22=j+'D';
    if((s1==s11&&s2==s22)||(s2==s11&&s1==s22))
    {
        cout<<0;
        break;
    }
    if(i==17){
        cout<<1;
    }
}
for(int i=0;i<18;i++){
        int ss=0;
    string s11,s22;
    char arr[6]={'A','B','C','D','F'};
    int j=i+1;
    for(int n=0;n<6;n++){
    s11=j+arr[n];
    s22=j+arr[n+1];
    if((s1==s11&&s2==s22))
    {
        cout<<0;
        ss=1;
        break;
    }
    }
    if(i==17){
        cout<<1;
    }
if(ss==1)
    break;
}
return 0;
}
