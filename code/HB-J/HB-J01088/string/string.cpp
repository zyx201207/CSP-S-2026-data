#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string a;
    int n;
    cin>>n;
    long long c=1;
    for (int i=1;i<=n;i++){
        long long x;
        cin>>x;
        char b;
        cin>>b;
        for (long long j=1;j<=x;j++){
            a[c]=b;
            c++;
        }
    }
    c--;
    int sum=0;
    string b;
    for (int i=1;i<=c;i++){
        b[i]=a[c-i+1];
    }
    for (int i=1;i<=c/2;i++){
        if (b[i]!=a[i]) sum++;
    }

    cout<<sum;
    return 0;
}
