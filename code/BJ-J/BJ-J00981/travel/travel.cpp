#include<bits/stdc++.h>
using namespace std;
int main(){
    int c1,c2;
    char s1[4],s2[4];
    cin>>c1;
    for(int i=1;i<=3;i++){
        cin>>s1[i];
    }
    cin>>c2;
    for(int i=1;i<=3;i++){
        cin>>s2[i];
    }
    if(c1==c2){
        cout<<1;
        if(s1[1]==s2[1]&&s1[2]==s2[2]){
            cout<<1;
            if((s1[3]<='C'&&s2[3]<='C')||(s1[3]>='D'&&s2[3]>='D')){
                cout<<1;
                int a,b;
                if(s1[3]!='F') a=s1[3]-64;
                else a=5;
                if(s2[3]!='F') b=s2[3]-64;
                else b=5;
                if(a-b==1 || a-b==-1) cout<<1;
                else cout<<0;
            }
            else cout<<0<<0;
        }
        else cout<<0<<0<<0;
    }
    else cout<<0<<0<<0<<0;
    cout<<endl;
    return 0;
}