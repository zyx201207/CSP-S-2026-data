#include<bits/stdc++.h>
using namespace std;
int n1,n2,m1,m2,s1,s2;
char t1,t2;
int main (){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n1>>m1>>t1>>n2>>m2>>t2;
    s1=t1-'A'+1;
    s2=t2-'A'+1;
    if(n1==n2){
        cout<<'1';
        if(m1==m2){
            cout<<'1';
            if(s1<4&&s2<4){
                cout<<'1';
                if(abs(s1-s2)!=2) cout<<'1';
                else cout<<'0';
            }
            else if(s1>=4&&s2>=4){
                cout<<"11";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
