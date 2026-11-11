#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int a=0;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2&&c1[0]!='1'&&c2[0]!='1'&&c1[1]!='6'&&c2[1]!='6'){
        cout<<"1";
        a++;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<"1";
            a++;
            if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'||s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
                cout<<"1";
                a++;
                if((s1[2]==s2[2]-1||s1[2]==s2[2]+1)&&s1[2]-1>='A'&&s1[2]+1<='C'||s2[2]-1>='A'&&s2[2]+1<='C'||(s1[2]=='D'&&s2[2]=='F'||s2[2]=='D'&&s1[2]=='F')){
                    cout<<"1";
                    a++;
                }
            }
        }
    }
    for(int i=0;i<(4-a);i++){
        cout<<"0";
    }
    return 0;
}
