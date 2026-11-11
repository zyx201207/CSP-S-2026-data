#include<bits/stdc++.h>
using namespace std;
struct str{
    long long s;
    string d;
};
str a[1000100];
int c[1000100];
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
    cin>>a[i];
    c[i]=a[i].s;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=c[i];j++){
            s+=a[i].d;
            m++;
        }
    }
    if(s%2==0)
    {
        for(int i=1;i<=m/2;i++){
            if(a[i].d!=a[m-i+1])
            {
                ans++;
            }
        }
    }
    else{
        for(int i=1;i<=(m/2)+1){
            if(a[i].d!=a[m-i+1]){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}