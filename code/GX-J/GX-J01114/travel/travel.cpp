#include<bits/stdc++.h>
using namespace std;


int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string c,m;
    string d,n;
    cin>>a;
    cin>>c;
    cin>>b;
    cin>>d;
    m=c[2];
    n=d[2];
    if(a==b){
        cout<<1;
        if(c[0]==d[0]&&c[1]==d[1]){
            cout<<1;
            if((m=="A"||m=="B")||m=="C"){
                if((n=="A"||n=="B")||n=="C"){
                    cout<<1<<0;
                    }
                else cout<<1<<0;
                }
            else if(m=="D"||m=="F"){
                    if(n=="D"||n=="F")cout<<1<<0;
            else if(m=="B"||m=="D"){
                if(n=="B"||n=="D")cout<<1<<1;
            }
            }
        }
        else cout<<0<<0<<0;
    }
    else cout<<0<<0<<0<<0;






    return 0;
}








