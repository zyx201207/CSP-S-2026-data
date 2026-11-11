#include<bits/stdc++.h>
using namespace std;
string ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a1,a2;
    char q1,q2,q3,p1,p2,p3;
    cin>>a1>>q1>>q2>>q3>>a2>>p1>>p2>>p3;
    if(a1==a2){
        cout<<1;
        if(q1==p1&&q2==p2){
            cout<<1;
            if(q3>='A'&&q3<='C'&&p3>='A'&&p3<='C'||q3>='D'&&q3<='F'&&p3>='D'&&p3<='F'){
                cout<<1;
                if(q3=='A'&&p3=='B'||q3=='B'&&(p3=='C'||p3=='A')||q3=='C'&&p3=='B'||q3=='D'&&p3=='F'||q3=='F'&&p3=='D'){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<"00";
            }

        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
