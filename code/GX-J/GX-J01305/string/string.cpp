#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n, s = 0, rt = 0, xy = 0;
    cin >>n;
    int num[n], c[n];
    for (int i = 0; i < n; i++){
        cin  >> num[i] >> c[i];
        s += num[i];
    }
    int ar[s];
    for (int i = 0;i < n; i++){
        for(int j = 0; j < num[i]; j++){
            ar[rt] = c[i];
            rt++;
        }
    }

    for(int i = 0;i < s/2; i++){
        if (ar[i]!=ar[s-1-i]){
            xy++;
        }
    }
    cout << xy;
    return 0;
}
