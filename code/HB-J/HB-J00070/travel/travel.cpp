#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool f[4]={0,0,0,0};
    if(c1==c2) f[0]=1;
    int a=(s1[0]-'0')*10+(s1[1]-'0');
    int b=(s2[0]-'0')*10+(s2[1]-'0');
    if(f[0]){
        if(a==b) f[1]=1;
        if(f[1]){
            bool f1,f2;
            if(s1[2]>='A'&&s1[2]<='C') f1=1;
            else f1=0;
            if(s2[2]>='A'&&s2[2]<='C') f2=1;
            else f2=0;
            if(f1==f2) f[2]=1;
            if(f[2]){
                if(!(f1||f2)) f[3]=1;
                else if(abs(s1[2]-s2[2])==1) f[3]=1;
            }
        }
    }
    for(int i=0;i<4;i++) cout<<f[i];
    return 0;
}
