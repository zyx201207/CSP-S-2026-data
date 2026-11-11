#include<bits/stdc++.h>
using namespace std;
    int a[100000]={};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,c;
    string b,d;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;
    if(a==c){
        cout<<1;
        if('d'<='b'+5 and 'd'>='b'){
            cout<<1;
            if('b'<='E' and 'd'>='D'){
                if('d'=='b'+1){
                    cout<<0<<0;
                }
                else{
                    cout<<1<<1;
                }
            }
            else{
                if('b'+1=='d' or 'b'-1=='d'){
                    cout<<1<<1;
                }
                else{
                    cout<<0<<0;
                }
            }

        }
        else{
            cout<<0<<0<<0;
        }
    }
    else{
        cout<<0<<0<<0<<0;
    }


    return 0;


}
