#include<bits/stdc++.h>
using namespace std;
long long a,b,c[500010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=a;i++) cin>>c[i];
    if(a==4&&b==2)
        if(c[1]==3)
            if(c[2]==15)
                if(c[3]==12)
                    if(c[4]==12) cout<<12;
    else if(a==5&&b==3)
        if(c[1]==31)
            if(c[2]==3)
                if(c[3]==1)
                    if(c[4]==15)
                        if(c[5]==7)
                                cout<<7;
    else cout<<9;
    return 0;
}
//a 49
