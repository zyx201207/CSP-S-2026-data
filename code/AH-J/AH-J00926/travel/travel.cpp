#include<bits/stdc++.h>
using namespace std;
int s[4];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string r1,r2,x1,x2;
    cin>>r1>>r2>>x1>>x2;
    if(r1==x1){
        s[0]=1;
        if(r2[0]==x2[0]&&r2[1]==x2[1]){
            s[1]=1;
            int a=0,b=0;
            if(r2[2]=='A'||r2[2]=='B'||r2[2]=='C'){
                a=1;
            }
            else if(r2[2]=='D'||r2[2]=='F'){
                a=2;
            }
            if(x2[2]=='A'||x2[2]=='B'||x2[2]=='C'){
                b=1;
            }
            else if(x2[2]=='D'||x2[2]=='F'){
                b=2;
            }
            if(a==b){
                s[2]=1;
                int c=r2[2],d=x2[2];
                if(abs(c-d)==1){
                    s[3]=1;
                }
            }
        }
    }
    for(int i=0;i<4;i++){
        cout<<s[i];
    }
    return 0;
}
//02 01A 02 01B
