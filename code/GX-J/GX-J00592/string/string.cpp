#include <bits/stdc++.h>
using namespace std;
long long a[1000010];
string c[1000010];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    long long cnt=0;
    string l="",l1="";
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
        for(int j=1;j<=a[i];j++){
            l = l+c[i];
        }
    }
    long long len=l.size();
    for(long long i=len-1;i>=0;i--){
        l1 = l1+l[i];
    }
    for(long long i=0;i<len-1;i++){
        if(l1[i]!=l[i]){
            l1[i] = l[i];
            l[len-1-i] = l[i];
            cnt++;
        }
    }
    cout<<cnt;

    return 0;
}
