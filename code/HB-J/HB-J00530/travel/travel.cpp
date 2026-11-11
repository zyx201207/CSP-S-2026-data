#include <bits/stdc++.h>
using namespace std;

int main(){
//  freopen("travel.in","r",stdin);
//reopen("travel.out","w",stout);
    string s1,c1,s2,c2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    else{
        cout<<"1";
    }
    int len1=s1.size();
    int len2=s2.size();
    string s;
    char a=s1[2];
    cout<<a<<" ";
   if((s1[0]==0&&s2[0]==0)||(s1[0]==1&&s2[0]==1 ))  {
        if(s1[1]==s2[1]) {cout<<"1";}
        else{
            cout<<"000";
            return 0;
        }
        if((s1[2]=="D")||(s1[2]=="F"))
           if((s1[2]=="D")||(s1[2]=="F")){
            cout<<"11";
            return 0;
           }
           else{
            cout<<"00";
            return 0;
           }
        }
        else{
            if((s1[2]!="D")&&(s1[2]!="F")){
                cout<<"1";
            }
            else{
                cout<<"00";
            }
            char a=s1[2];
        }
   }
    cout<<s;

    return 0;
}
// 01 01A 01 01B

