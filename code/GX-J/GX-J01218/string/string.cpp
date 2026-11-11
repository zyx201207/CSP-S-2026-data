#include <bits/stdc++.h>
using namespace std;
long long s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int cnt=0;
    int a=[];
    string c=[];


    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        sort(c[i]+1,c[i]+n+1,cmp);
        cnt++;
    }
    cout<<cnt;

    return 0;
}
