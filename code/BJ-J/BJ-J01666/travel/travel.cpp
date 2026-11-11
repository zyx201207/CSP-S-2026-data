#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
    }else{
        cout<<"0000";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(b.substr(0,2)==d.substr(0,2)){
        cout<<1;
    }
    else {
        cout<<"000";
        fclose(stdin);
        fclose(stdout);
        return 0;

    }
    if(((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||((b[2]=='D'||b[2]=='E')&&(d[2]=='D'||d[2]=='E'))){
        cout<<1;
    }
    else {
        cout<<"00";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A'))||((b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B'))||((b[2]=='D'&&d[2]=='E')||(b[2]=='E'&&d[2]=='D'))){
        cout<<1;
    }
    else {
        cout<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
