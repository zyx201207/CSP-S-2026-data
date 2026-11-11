#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int nm=0;
long long an=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>nm;
    struct tre{
        long long s=0;
        string m;
    }a[N];
    string sm;
    for(int i=1;i<=nm;i++){
        cin>>a[i].s>>a[i].m;
    }
    for(int i=1;i<=nm;i++){
        for(int j=1;j<=a[i].s;j++){
            sm+=a[i].m;
        }
    }
    int len = sm.size();
    for(int i=0;i<len/2;i++){
        if(sm[i]!=sm[len-1-i]) an++;
    }
    cout<<an;
    return 0;
}
