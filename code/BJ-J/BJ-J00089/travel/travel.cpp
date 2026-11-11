#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string strA1,strA2,strB1,strB2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>strA1>>strA2>>strB1>>strB2;
    if(strA1==strB1)
        printf("1");
    else{
        printf("0000");
        return 0;
    }
    if(strA2[0]==strB2[0]&&strA2[1]==strB2[1])
        printf("1");
    else{
        printf("000");
        return 0;
    }
    if(strA2[2]<='C'&&strB2[2]<='C'){
        printf("1");
        if((ll)(abs(strA2[2]-strB2[2])==1ll))
            printf("1");
        else
            printf("0");
    }
    else if(strA2[2]>'C'&&strB2[2]>'C')
        printf("11");
    else
        printf("00");
    return 0;
}
