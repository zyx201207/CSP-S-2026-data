#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long a,b,c[100000000],s;
    cin>>a>>b;
    for(int i=0;i<=a-1;i++){
        cin>>c[i];
    }
    s=0;
    for(int i=0;i<=b-1;i++){
        for(int j=0;j<=a-2;j++){
            s=max(c[j] and c[j+1],c[j+1] and s)
        }
    }
    cout<<s;
    return 0;
}