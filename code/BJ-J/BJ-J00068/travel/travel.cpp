#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string C1,s1,C2,s2;
    cin>>C1>>s1>>C2>>s2;
    int l1,l2,a1,a2;

    l1=s1[0]-'0'; l1=l1*10;
    l1=l1+s1[1]-'0';
    l2=s2[0]-'0'; l2=l2*10;
    l2=l2+s2[1]-'0';

    a1=s1[2]-'A'+1;
    a2=s2[2]-'A'+1;
    if(a1==4) a1++;
    if(a2==4) a2++;

    if(C1==C2){
        cout<<"1";
        if(l1==l2){
            cout<<"1";
            if((a1<=3 && a2<=3) || (a1>4 && a2>4)){
                cout<<"1";
                int c=a1-a2;
                if(abs(c)==1){
                    cout<<"1";
                }
                else{
                    cout<<"0";
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
