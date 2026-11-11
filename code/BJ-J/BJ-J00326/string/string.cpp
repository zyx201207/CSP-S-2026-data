#include<bits/stdc++.h>
using namespace std;
long long n,a[2000010],cnt=0;
long long lb;
string b,c;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=0;i<=(n-1);i++){
        cin>>a[i];
        cin>>c[i];
        for(long long j=1;j<=a[i];j++){
            b+=c[i];
        }
        lb=b.length();

    }
    /*for(int j=0;j<=(lb-1);j++){
            cout<<b[j];
    }*/
    cnt=0;
    for(long long i=(lb-1);i>=0;i--){
        if(b[i]!=b[(lb-1)-i]){
            b[i]=b[(lb-1)-i];
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
