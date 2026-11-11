#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    string f="";
    string k="";
    f+=b[0],f+=b[1],k+=d[0],k+=d[1];
    cout<<(a==c?"1":"0")<<(f==k&&a==c?"1":"0")<<(f==k&&a==c&&((b[2]=='A'&&d[2]=='B')||(b[2]=='A'&&d[2]=='C')||(b[2]=='B'&&d[2]=='C')||(b[2]=='D'&&d[2]=='F')||(b[2]=='B'&&d[2]=='A')||(b[2]=='C'&&d[2]=='A')||(b[2]=='C'&&d[2]=='B')||(b[2]=='F'&&d[2]=='D'))?"1":"0")<<(f==k&&a==c&&abs(b[2]-d[2])==1&&(!((b[2]=='D'&&d[2]=='C')||(b[2]=='C'&&d[2]=='D'))));
    fclose(stdin);
    fclose(stdout);
}
