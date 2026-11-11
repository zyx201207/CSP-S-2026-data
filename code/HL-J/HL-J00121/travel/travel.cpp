#include<bits/stdc++.h>
using namespace std;
bool a[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0]&& c1[1]==c2[1]){
        a[1]=1;
    }else{
        a[1]=0;
        a[2]=0;
        a[3]=0;
        a[4]=0;
        cout<<a[1]<<a[2]<<a[3]<<a[4];
        return 0;
    }
    if(a[1]==1 && s1[0]==s2[0] && s1[1]==s2[1]){
        a[2]=1;
    }else{
        a[2]=0;
        a[3]=0;
        a[4]=0;
        cout<<a[1]<<a[2]<<a[3]<<a[4];
        return 0;
    }
    if(a[2]==1&&s1[2]=='A' && s2[2]=='B'){
        a[3]=1;a[4]=1;
    }else if(a[2]==1&&s1[2]=='A'&&s2[2]=='C'){
        a[3]=1;a[4]=0;
    }else if(a[2]==1&&s1[2]=='B' && s2[2]=='C'){
        a[3]=1;a[4]=1;
    }else if(a[2]==1&&s1[2]=='D'&&s2[2]=='F'){
        a[3]=1;a[4]=1;
    }else if(a[2]==1&&s2[2]=='A' && s1[2]=='B'){
        a[3]=1;a[4]=1;
    }else if(a[2]==1&&s2[2]=='A'&&s1[2]=='C'){
        a[3]=1;a[4]=0;
    }else if(a[2]==1&&s2[2]=='B' && s1[2]=='C'){
        a[3]=1;a[4]=1;
    }else if(a[2]==1&&s2[2]=='D'&&s1[2]=='F'){
        a[3]=1;a[4]=1;
    }else{
        a[3]=0;a[4]=0;
    }
    cout<<a[1]<<a[2]<<a[3]<<a[4];
    return 0;
}
