#include <bits/stdc++.h>
using namespace std;
char cx,cy;
char sx[20005],sy[20005];

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cx>>sx>>cy>>sy;
    if(cx==cy){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
