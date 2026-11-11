#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
long long n,x,ztb,a[N];
string S,c[N];
int f(int l,int r){
    for(int i = 0;i < x/2;i++){
        if(S[l] == S[r]){
            l++;
            r--;
        }else{
            ztb++;
            l++;
            r--;
        }
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> a[i] >> c[i];
        x += a[i];
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<a[i];j++){
            S += c[i];
        }
    }
    f(0,x-1);
    cout << ztb;
    return 0;
}
