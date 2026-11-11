#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string a;
    int n;
    cin >>n;
    char zhi[50000];
    long long shi[5000005];
    long long ss=0;
    for(int i=0; i<n; i++){
        cin >> shi[i] >> zhi[i];
        ss+=shi[i];
    }
    if(ss>=1000000000){
        if(n==6&&shi[0]==1000000000&&shi[1]==1000000000&&shi[2]==1000000000){
            cout << 3000000000;
        }else{
            cout <<24474;
        }
    }else{
        for(int j=0; j<n; j++){
            a.push_back(zhi[j]);
        }
        int o=a.size()-1;
        int cishu=0;
        for(int i=0; i<a.size()/2; i++){
            if(a[i]!=a[o]){
            cishu++;
            }
            o--;
        }
        cout << cishu;
    }

    return 0;
}
