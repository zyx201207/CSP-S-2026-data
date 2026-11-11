#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("and.in","r",stdin);
    //freoprn("and.out","w",stdout);
    int n,m;
    char s[1000001],h[1000001];
    int a[10001],g=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=x;
        s[i]=x%2;
        x/=2;
        g++;
    }
    int c=0;
    for(int i=g-1;i>=0;i--){
        h[c]=s[i];
        c++;
    }
    return 0;
}
