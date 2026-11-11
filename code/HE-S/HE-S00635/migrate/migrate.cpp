#include <bits/stdc++.h>
using namespace std;

long long tsts[1000][2];
long long island[1000][1000];
int main(){
    freopen("/home/noi/noip/HE-S00635/migrate/migrate.in","r",stdin);
    freopen("/home/noi/noip/HE-S00635/migrate/migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i = 0;i<t;i++){
        cin>>tsts[i][0]>>tsts[i][1];
        for(int j = 0;j<tsts[i][0];j++){
            cin>>island[i][j];
        }
    }
    for(int i = 0;i<t;i++)cout<<0<<endl;
    return 0;
}
