#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string1.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string L = "";
    long long z = -1;
    int c = 0;
    for(int i = 1;i <= n;i++){
        int longth;
        char word;
        cin >> longth;
        cin >> word;
        L += longth*word;
        z+=longth;
    }
    long long j = 0;
    while(j <= z){
        if(L[j] != L[z]){
            c++;
        }
        j++;
        z--;
    }
    cout << c;
    return 0;
}
