#include<bits/stdc++.h>
using namespace std;

int c1,c2,p1,p2;
string s1,s2,ans;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    p1=(s1[0]-'0')*10+(s1[1]-'0');
    p2=(s2[0]-'0')*10+(s2[1]-'0');
    if(c1==c2){
        ans+='1';
        if(p1==p2){
            ans+='1';
            if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')
            {
                ans+='1';
                if(abs(s1[2]-s2[2])==1)
                    ans+='1';
                else
                    ans+='0';
            }
            else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
                ans+="11";
            }
            else{
                ans+="00";
            }
        }
        else{
            ans+="000";
        }

    }
    else{
        ans+="0000";
    }
    for(int i=0;i<=3;i++)
        cout<<ans[i];

    return 0;
}
