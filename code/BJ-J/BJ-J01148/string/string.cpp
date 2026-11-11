#include <bits/stdc++.h>
using namespace std;
char c[10001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,m=0,cnt=0;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        int a;
        char d;
        cin>>a;
        m+=a;
        cin>>d;
        for(int j=1;j<=a;j++){
            c[j]=d;
        }
    }
    int x=1;
    for(int i=m;i>=m/2;i--){
        if(c[i]!=c[x]){
            cnt++;
        }
        x++;
    }
    cout<<cnt;
    return 0;
}
