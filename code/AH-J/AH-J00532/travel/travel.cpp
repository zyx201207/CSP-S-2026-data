#include<iostream>


using namespace std;
using LL =long long;

LL seat[100];

string c1,c2,s1,s2,ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    seat['A']=1;
    seat['B']=2;
    seat['C']=3;
    seat['D']=4;
    seat['F']=5;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        ans+="1";
        string r1,r2;
        r1=s1[0]+s1[1];
        r2=s2[0]+s2[1];
        if(r1==r2){
            ans=ans+"1";
            if((seat[s1[2]]<=3&&seat[s2[2]]<=3)||(seat[s1[2]])>=4&&seat[s2[2]]>=4){
                ans+="1";
                if(seat[s1[2]]==seat[s2[2]]-1||seat[s1[2]]==seat[s2[2]]+1)
                    ans+="1";
                else ans+="0";
            }else ans+="00";
        }else ans+="000";
    }else ans="0000";
    cout<<ans;
    return 0;
}
