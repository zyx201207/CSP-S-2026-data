#include<bits/stdc++.h>
using namespace std;
string s1,s2,p1,p2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>p1>>s2>>p2;
    int ans=1;
    if(s1[0]==s2[0] and s1[1]==s2[1]){
        printf("%d",1);
        if(p1[0]==p2[0] and p1[1]==p2[1]){
            printf("%d",1);
            if(((p1[2]>='A' and p1[2]<='C') and (p2[2]>='A' and p2[2]<='C')) or ((p1[2]>='D' and p1[2]<='F') and (p2[2]>='D' and p2[2]<='F'))){
                printf("%d",1);
                if(p1[2]+1==p2[2] or p1[2]-1==p2[2]){
                    printf("%d",1);
                }else{
                    printf("%d",0);
                }
            }else{
                printf("%d%d",0,0);
            }
        }else{
            printf("%d%d%d",0,0,0);
        }
    }else{
        printf("%d%d%d%d",0,0,0,0);
    }
    return 0;


}
