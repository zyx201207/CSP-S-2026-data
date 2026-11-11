#include <bits/stdc++.h>

using namespace std;
string rc,xc,rs,xs;
int c=0,s=0,r=0,n=0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>> rc>>rs>>xc>>xs;
    if(rc==xc ){
        c=1;
        if(rs[0]==xs[0] && rs[1]==xs[1]) {
            s=1;
            if(rs[2]<='C' && xs[2]<='C'){
                r=1;
                int j=rs[2],i=xs[2];
                int b =j-i;
                if(b==1 || b==-1){
                    n=1;
                }
                }
            if((rs[2]=='D' && xs[2]=='F')||(rs[2]=='F' )&& (xs[2]=='D')){
                r=1;
                n=1;
                }
            }

}
    cout<<c<<s<<r<<n;

    return 0;
}
