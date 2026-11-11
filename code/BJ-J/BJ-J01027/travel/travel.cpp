#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,res;
bool flag=0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0]&&c1[1]==c2[1]){
        res+="1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            res+="1";
            if((s1[2]!='F'&&s2[2]!='F'&&s1[2]!='D'&&s2[2]!='D')||(s1[2]+s2[2]-2*'A')==8){
                res+="1";
                if((abs(s1[2]-s2[2])==1&&s1[2]!='D'&&s2[2]!='D')||(s1[2]+s2[2]-2*'A')==8){
                    res+="1";
                }else{
                    res+='0';
                }
            }else{
                res+="00";
            }
        }else{
            res+="000";
        }
    }else{
        res+="0000";
    }
    cout<<res<<"\n";
    return 0;
}