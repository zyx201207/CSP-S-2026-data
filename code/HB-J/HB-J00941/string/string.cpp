#include<bits/stdc++.h>
using namespace std;
int n;
long long s;
vector <char> a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    int maxa=0;
    for(int i=1;i<=n;i++){
            int r;
    char zd;
        cin >> r>>zd;
        if(maxa<r){
            r=maxa;
        }
        for(int j=0;j<r;j++){
            a.push_back(zd);
        }
        s+=r;
    }
    long long m=0;
    for(int i=0;i<(s+1)/2;i++){
        if(a[i]!=a[s-1-i]){
            m++;
        }
    }
    cout << m;
    return 0;
}
