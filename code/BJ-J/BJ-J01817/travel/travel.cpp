#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a, a1, b, b1;
    char a2, b2;
    scanf("%d %d%c %d %d%c",&a,&a1,&a2,&b,&b1,&b2);
    if(a==b){
        cout << 1;
        if(a1==b1){
            cout << 1;
            if((a2=='A' || a2=='B' || a2 == 'C') && (b2=='A' || b2=='B' || b2 == 'C')){
                cout << 1;
                if(a2=='B'||b2=='B') cout << 1;
                else cout << 0;
            }
            else if((a2=='D'||a2=='F') && (b2=='D'||b2=='F')){
                cout << 11;
            }
            else cout << "00";
        }
        else cout << "000";
    }
    else cout << "0000";
    puts("");
    return 0;
}