#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    string S = "";
    int n;
    cin >> n;
    for(int i = 0;i <= n;i++){
        int n1;
        string l;
        cin >> n1 >>l;
        for(int j = 0;j <= n1;j++){
            S+l;
        }
    }
    long long L = S.size();
    string Sf = "",Sb = "";
    for(int i = 0;i < L/2;i++){
        Sf+S[i];
    }
    for(int i = L;i > L/2;i--){
        Sb+S[i];
    }

    int num = 0;
    for(int i = 0;i > L/2;i++){
        if(Sf[i] != Sb[i]){
            num++;
        }
    }

    cout << num;

    return 0;
}
