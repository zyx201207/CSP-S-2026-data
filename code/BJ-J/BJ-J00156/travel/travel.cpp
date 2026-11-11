#include <iostream>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    //     车厢号
    string s1,s2;
    //  座位号
    int c1,c2;
    cin>>c1>>s1>>c2>>s2;
    //cout<<c1<<' '<<s1<<' '<<c2<<' '<<s2;
    bool flag=1;

    if(c1==c2)cout<<1;
    else{
        cout<<0;
        flag=0;
    }

    if((s1[0]==s2[0]&&s1[1]==s2[1])&&flag==1)cout<<1;
    else{
        cout<<0;
        flag=0;
    }

    if( ((s1[2]>'C'&&s2[2]>'C')||(s1[2]<='C'&&s2[2]<='C'))&&flag==1 ){
        cout<<1;
    }
    else{
        cout<<0;
        flag=0;
    }

    if((s1[2]-s2[2]==1||s2[2]-s1[2]==1)&&flag==1)cout<<1;
    else cout<<0;
    return 0;
}
