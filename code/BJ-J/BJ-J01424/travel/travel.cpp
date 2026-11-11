#include<bits/stdc++.h>
using namespace std;
string c,ss,d,aa;
bool flag1,flag2,flag3;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>ss>>d>>aa;
    if(c==d){
        cout<<1;
        string s=ss.substr(0,2);
        string z=aa.substr(0,2);
        
        if(s==z){
            cout<<1;
            char x=ss[2];
            char z=aa[2];
            //cout<<x<< " "<<z<<endl;
            if((x=='A'&&z=='B') || (x=='A'&&z=='C') || (x=='B'&&z=='C')||(x=='D'&&z=='E')||(x=='B'&&z=='A') || (x=='C'&&z=='A') || (x=='C'&&z=='B')||(x=='E'&&z=='D')){
                    cout<<1;
                    if((x=='A'&&z=='B') || (x=='B'&&z=='C')||(x=='D'&&z=='E')||(x=='B'&&z=='A') || (x=='C'&&z=='B')||(x=='E'&&z=='D')){
                        cout<<1;
                    }else{cout<<0;}


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
