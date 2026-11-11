#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll side[128];
ll place[128];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    side['A']=1,place['A']=1;
    side['B']=1,place['B']=2;
    side['C']=1,place['C']=3;
    side['D']=2,place['D']=4;
    side['F']=2,place['F']=5;
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    ll row1=s1[0]*10+s1[1];
    ll row2=s2[0]*10+s2[1];
    if(c1==c2){
        cout<<'1';
        if(row1==row2){
            cout<<'1';
            if(side[s1[2]]==side[s2[2]]){
                cout<<'1';
                if(abs(place[s1[2]]-place[s2[2]])==1){
                    cout<<'1';
                }
                else{
                    cout<<'0';
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
