#include <bits/stdc++.h>;
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string n,n2,m,m2;
    int y=0;
    cin>>n>>n2>>m>>m2;
    string n1[3];
    string m1[3];
    for (int i=0;i<3;i++){
        n1[i]=n2[i];
        m1[i]=m2[i];
    }
    if(n==m) {
        cout<<1;
        if(n1[0]+n1[1]==m1[0]+m1[1]) {
            cout<<1;
            if(n1[2]=="A" or n1[2]=="B" or n1[2]=="C"){
                if(m1[2]=="A" or m1[2]=="B" or m1[2]=="C"){
                    cout<<1;
                    if(n1[2]=="A" and m1[2]=="B" or n1[2]=="B" and m1[2]=="C" or n1[2]=="B" and m1[2]=="A" or n1[2]=="C" and m1[2]=="B"){
                        cout<<1;
                    }
                    else y=1;
                }
                else cout<<0<<0;
            }
            else{
                if(m1[2]=="D" or m1[2]=="F"){
                    cout<<1;
                    cout<<1;
                }
                else cout<<0<<0;
            }
        }
        else cout<<0<<0<<0;
        if(y==1) cout<<0;
    }
    else cout<<0<<0<<0<<0;
    return 0;
}
