#include<bits/stdc++.h>
using namespace std;
int c[3];
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c[1]>>s1>>c[2]>>s2;
    char sub1=s1[2],sub2=s2[2];
    if(c[1]!=c[2]){
        cout<<"0000"<<endl;
        return 0;
    }
    else{
        cout<<"1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<"1";
            bool flag=false;
            if(sub1<='C'&&sub2<='C') flag=true;
            else if(sub1>='D'&&sub2>='D') flag=true;
            if(flag) cout<<"1";
            else cout<<"0";
            int sub=abs((sub1-'0')-(sub2-'0'));
            if(sub==1&&flag) cout<<"1";
            else cout<<"0";
        }
        else{
            cout<<"000"<<endl;
            return 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
}
