#include<bits/stdc++.h>
using namespace std;
bool pd[4]={};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int sum=(s1[2]>s2[2]?s1[2]-s2[2]:s2[2]-s1[2]);
    if(c1==c2){
        pd[0]=1;
        if(sum<=5){
            pd[1]=1;
            if(sum<=2){
                pd[2]=1;
                if(sum==1||sum==2&&s1[2]=='F'||s2[2]=='F') pd[3]=1;
            }
        }
    }
    cout<<pd[0]<<pd[1]<<pd[2]<<pd[3];
    return 0;
}
