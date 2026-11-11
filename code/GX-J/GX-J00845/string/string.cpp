#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, cnt = 0;
    cin >> n;
    long long a; char c;
    string s = "";
    for(long long i = 0;i < n;i++){
        cin >> a >> c;
        for(long long j = 0;j < a;j++)s += c;
    }
    long long mid = s.size()/2;
    //char sq[1000005], sh[1000005];
    string sq, sh;
    for(int i = 0;i <= mid;i++){
        sq[i] = s[i];
        //cout << sq[i];
    }
    //cout << endl;
    for(int i = s.size();i >= mid;i--){
        sh[i] = s[i];
        //cout << sh[i];
    }
    //cout << endl;
    for(int i = 0;i < s.size()/2;i++){
        if(sq[i] != sh[mid-i] ){
            //sh[i] = sq[i];
            cnt ++;
        }
    }

    cout << cnt;
    return 0;
}
