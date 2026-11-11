#include<bits/stdc++.h>
using namespace std;
string s[200005];
/*void turn(int x,int q){
    int i = 1;
    while(1){
        if(x<2){
            s[q][i] = x;
            return;
        }
        s[q][i] = x%2;
        x/=2;
    }
}*/
int main(){
    freopen("and.out", "w", stdout);
    freopen("and.in", "r", stdin);
    long long n ,t, len[200005],Max1 = 0;
    cin>>n>>t;
    for(int i = 1;i <= n;i++){
        long long m;
        cin >> m;
        Max1 = max(Max1,m);
        /*turn(m,i);
        len[i] = s[i].size();*/
    }
    cout << Max1;
    return 0;
}

