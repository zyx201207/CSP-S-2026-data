#include<bits/stdc++.h>
using namespace std;
//A=65
//C=67

int R,X;
string s1,s2;
int ans[10];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>R>>s1>>X>>s2;
    if(R==X){//是否在同一个车厢
        ans[1]=1;
        if(s1[0]==s2[0]){//大判断，第一个字符
            if(s1[1]==s2[1]){
                ans[2]=1;
                if(s1[2]>=65 && s1[2]<=67 && s2[2]>=65 && s2[2]<=67){
                    ans[3]=1;
                    if(s1[2]-s2[2]==1 || s1[2]-s2[2]==-1){
                        ans[4]=1;
                    }else{
                        ans[4]=0;
                    }
                }else if((s1[2]==68 && s2[2]==70) || (s1[2]==70 && s2[2]==68)){
                    ans[3]=1;
                    ans[4]=1;
                }else{
                    ans[3]=0;
                }
            }else if(s1[1]!=s2[1]){
                ans[2]=0;
                ans[3]=0;
                ans[4]=0;
            }
        }else if(s1[0]!=s2[0]){//大判断，第一个字符
            ans[2]=0;
            ans[3]=0;
            ans[4]=0;
        }

    }else if(R!=X){//是否在同一个车厢
        ans[1]=0;
        ans[2]=0;
        ans[3]=0;
        ans[4]=0;
    }
    for(int i=1;i<=4;i++){
        cout<<ans[i];
    }
    return 0;
}
//Brian_Birch
