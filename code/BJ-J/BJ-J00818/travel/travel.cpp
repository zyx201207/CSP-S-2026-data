#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c,s,cc,ss;
    cin>>c>>s>>cc>>ss;
    if(c==cc){
        cout<<"1";
    }else {
        cout<<"0000";
        return 0;
    }
    if(s[0]==ss[0]&&s[1]==ss[1]){
        cout<<1;
    }else{
        cout<<"000";
        return 0;
    }
    if(s[2]>='A'&&s[2]<='C'&&ss[2]>='A'&&ss[2]<='C'||s[2]>='D'&&s[2]<='E'&&ss[2]>='D'&&ss[2]<='E'){
        cout<<"1";
    }else {
        cout<<"00";
        return 0;
    }
    if(s[2]==ss[2]||s[2]==ss[2]+1||s[2]==ss[2]-1){
        cout<<"1";
    }else cout<<"0";



    fclose(stdin);
    fclose(stdout);

    return 0;
}

