#include<iostream>
using namespace std;
bool same[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string c,d;
    cin>>a>>c>>b>>d;
    same[1]=(a==b);
    same[2]=(c[1]==d[1]&&c[0]==d[0]);
    same[3]=(c[2]>'C' && d[2]>'C'||c[2]<='C' && d[2]<='C');
    same[4]=(min(c[2],d[2])+1==max(c[2],d[2])&&min(c[2],d[2])!='C'||min(c[2],d[2])=='D'&&max(c[2],d[2])=='F');
    bool f=1;
    for(int i=1;i<=4;i++){
        cout<<(f&&same[i]);
    }
    return 0;
}
