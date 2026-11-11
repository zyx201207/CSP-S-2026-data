#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.in","w",stdout);
    int n,cnt=0;
    cin>>n;
    string c;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    long long l=0;
    for(int i=1;i<=n;i++){
        l+=a[i];
    }
    string st;
    int k=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            k++;
            st[k]=c[i];
        }
    }
    for(int i=1;i<=l;i++){
        if(st[i]!=st[l-i+1]){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
