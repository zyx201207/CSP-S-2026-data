#include <bits/stdc++.h>
using namespace std ;
int a[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    s1[2]-='A'-1;
    s2[2]-='A'-1;
    if(c1==c2){
        a[1]=1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            a[2]=1;
            if(s1[2]<=3&&s2[2]<=3||s1[2]>3&&s2[2]>3){
                a[3]=1;
                if((max(s1[2],s2[2])==min(s1[2],s2[2])+1&&max(s1[2],s2[2])!=4)||min(s1[2],s2[2])==4&&max(s1[2],s2[2])==6) a[4]=1;
            }
        }
    }
    cout<<a[1]<<a[2]<<a[3]<<a[4];
    return 0;
}
