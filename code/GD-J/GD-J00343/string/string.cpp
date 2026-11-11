#include<bits/stdc++.h>
using namespace std;
int a[100000];
char c[100000];
int ret[100000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string .out","w",stdout);
    int n;
    cin>>n;
    long long cnt=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>c[i];
        cnt+=a[i];
    }
    long long b=1e9+10;
    for(int i=0;i<n;i++)
    {
        ret[i]=cnt-a[i];
        if(ret[i]<b)
        {
            b=ret[i];
        }
    }
    cout<<b;
    return 0;
}
