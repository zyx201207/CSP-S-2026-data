#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string c,d;
    cin>> a>>c>>b>>d;
    if(a==b){
        cout<<1<<' ';
        if((int(c[0])-48)*10+(int(c[1])-48)==(int(d[0])-48)*10+(int(d[1])-48)){
            cout<<1<<' ';
            if(   ((c[2]=='A'||c[2]=='B'||c[2]=='C')&& (d[2]=='A'||d[2]=='B'||d[2]=='C'))  ||  ((c[2]=='D'||c[2]=='F')&& (d[2]=='D'||d[2]=='F'))   ){
                cout<<1<<' ';
                if(  int(c[2])-int(d[2])==1||int(d[2])-int(c[2])==1  ) cout<<1<<' ';
                else cout<<0<<' ';

            }
            else cout<<0<<' '<<0;

        }
        else cout<<0<<' '<<0<<' '<<0;

    }
    else cout<<0<<' '<<0<<' '<<0<<' '<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
