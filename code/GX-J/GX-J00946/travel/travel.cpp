#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    string a1,b1;
    cin >> a >> a1 >> b >> b1;
    if(a==b){
        cout << 1;
        if(a1[0]==b1[0] and a1[1]==b1[1]){
            cout << 1;
            if((a1[2]>='D' and b1[2]>='D')or(a1[2]<'D' and b1[2]<'D')){
                cout << 1;
                if(abs(a1[2]-b1[2])==1) cout << 1;
                else cout <<0;
            }
            else  cout << 0 << 0;
        }

        else cout <<0 << 0 << 0;
    }
    else cout << 0 << 0 << 0 << 0;

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    return 0;
}
