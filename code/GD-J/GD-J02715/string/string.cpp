#include <bits/stdc++.h>
using namespace std;
long long  n,a[10000000],sum;
string c[10000000],x;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++)
        {
            x+='c[i]';
        }
    }
    for(int i=1;i<=x.length()/2;i++)
    {
        if(x[i]!=x[x.length()-i+1])sum++;
    }
    cout<<sum<<endl;
    return 0;

}
