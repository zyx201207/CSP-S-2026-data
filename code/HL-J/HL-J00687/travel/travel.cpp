#include<bits/stdc++.h>
using namespace std;
string sr,sx;
string srr,sxx;
int r,x,cnt,ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> sr >> srr >> sx >> sxx;
    if(sr[0] == sx[0] && sr[1] == sx[1]){
        cout << "1";
        if(srr[0] == sxx[0] && srr[1] == sxx[1]){
            cout << "1";
            if(srr[2] == 'A' || srr[2] == 'B' || srr[2] == 'C') r = 0;
            else r = 1;
            if(sxx[2] == 'A' || sxx[2] == 'B' || sxx[2] == 'C') x = 0;
            else x = 1;
            if(r == x){
                cout << "1";
                if(srr[2] == 'A') cnt = 1;
                else if(srr[2] == 'B') cnt = 2;
                else if(srr[2] == 'C') cnt = 3;
                else if(srr[2] == 'D') cnt = 4;
                else cnt = 5;
                if(sxx[2] == 'A') ans = 1;
                else if(sxx[2] == 'B') ans = 2;
                else if(sxx[2] == 'C') ans = 3;
                else if(sxx[2] == 'D') ans = 4;
                else ans = 5;
                if(ans - cnt == 1 || ans - cnt == -1) cout << "1";
                else cout << "0";
            }else{
                cout << "00";
            }
        }
        else{
            cout << "000";
        }
    }
    else{
        cout << "0000";
    }
    return 0;
}
