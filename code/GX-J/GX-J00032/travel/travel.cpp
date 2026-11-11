#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        string s1,s2;
        s1=b.substr(0,2);
        s2=d.substr(0,2);
        if(s1==s2){
            cout<<"1";
            char x,y;
            x=b[2];
            y=d[2];
            if((x>='D'&&y>='D')||(x<='C'&&y<='C')){
                cout<<"1";
                int e,f;
                e=(int)x;
                f=(int)y;
                if(e-f==1||f-e==1){
                    cout<<"1";
                }else{
                    cout<<"0";
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
