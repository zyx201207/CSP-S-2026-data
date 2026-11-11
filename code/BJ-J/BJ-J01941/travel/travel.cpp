#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main()
{
    ios::sync_with_stdio(false),cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3) {
        cout<<"1";
        if(s2.substr(0,2)==s4.substr(0,2)){
            cout<<"1";
            if((s2.substr(2,1)=="A"&&(s4.substr(2,1)=="B"||s4.substr(2,1)=="C"))||(s2.substr(2,1)=="B"&&(s4.substr(2,1)=="A"||s4.substr(2,1)=="C"))||(s2.substr(2,1)=="C"&&(s4.substr(2,1)=="B"||s4.substr(2,1)=="A"))||(s2.substr(2,1)=="D"&&s4.substr(2,1)=="F")||(s2.substr(2,1)=="F"&&s4.substr(2,1)=="D")){
                cout<<"1";
                if((s2.substr(2,1)=="A"&&s4.substr(2,1)=="B")||(s2.substr(2,1)=="B"&&s4.substr(2,1)=="A")||(s2.substr(2,1)=="B"&&s4.substr(2,1)=="C")||(s2.substr(2,1)=="C"&&s4.substr(2,1)=="B")||(s2.substr(2,1)=="D"&&s4.substr(2,1)=="F")||(s2.substr(2,1)=="F"&&s4.substr(2,1)=="D")){
                    cout<<"1";
                }else cout<<"0";
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
