#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    string m;
    for(int i = 0;i < n;i++){
        char zi;
        int ge;
        cin >> ge >> zi;
        m += zi * ge;
    }
    int mlen = m.length(),cnt = 0;
    for(int i = 0;i < mlen;i++){
        if(m[i] != m[mlen - 1 - i]){
            m[mlen - 1 - i] = m[i];
            cnt++;
        }
    }
    cout << cnt << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
