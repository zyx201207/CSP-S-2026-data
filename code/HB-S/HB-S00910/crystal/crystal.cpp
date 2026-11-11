#include<bits/stdc++.h>
using namespace std;
long  n,m,a[20000],p,q;
float t;
int c,d;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        p+=a[i];
        
    }
    t=p%n;
    if(t>=0.5)
    q=p/n;
    else
    q=p/n+1;
    for(int j=0;j<n;j++)
    {
    m=m-(q-a[j]);
    d++;
    if(m==0&&a[j+1]!=q)
    break;
    }
    cout<<d;
    return 0;
}