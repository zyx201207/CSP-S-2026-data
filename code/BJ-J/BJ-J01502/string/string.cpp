#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,sum=0;
    cin>>n;
    string a,c;
    while(n--)
    {
        int m;
        string b;
        cin>>m>>b;

        for(int i=1;i<=m;i++){
            a+=b;
        }

    }
    int x=1;
    for(int i=n;i>=1;i--)
    {
        c[i]=a[x];
        x++;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=c[i])
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}

