#include<bits/stdc++.h>
#define ll long long
using namespace std;
string r1,r2,x1,x2,s;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r1>>r2>>x1>>x2;
    if(r1==x1){
        if(r2[0]==x2[0]&&r2[1]==x2[1]){
            s+=r2[2];
            s+=x2[2];
            sort(s.begin(),s.end());;
            if(s=="DF"||s=="AB"||s=="AC"||s=="BC"){
                if(s=="AB"||s=="BC"||s=="DF") cout<<"1111";
                else cout<<"1110";
            }
            else cout<<"1100";
        }
        else cout<<"1000";
    }
    else cout<<"0000";
    return 0;
}
