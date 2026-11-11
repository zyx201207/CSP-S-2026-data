#include<bits/stdc++.h>
using namespace std;
struct seat{
    int train;
    string id;
};
bool cmp(seat x,seat y){
    if(x.id > y.id){
        return true;
    }
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    seat a[2];
    sort(a,a+1,cmp);
    cin >> a[0].train >> a[0].id >> a[1].train >> a[1].id;
    if(a[0].train == a[1].train){
        cout << '1';
        if((a[0].id[0] == a[1].id[0])&&(a[0].id[1] == a[1].id[1])){
            cout << '1';
            if(((a[0].id[2] == 'F')&&(a[1].id[2] != 'D'))||(a[1].id[2] == 'D')){
                cout << "00";
            }else{
                cout << '1';
                if(a[0].id[2] - a[1].id[2] == -1){
                    cout << '1';
                }else{
                    cout << '0';
                }
            }
        }else{
            cout << "000";
        }
    }else{
        cout <<"0000";
    }
    return 0;
}
