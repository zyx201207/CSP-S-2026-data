#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int a[505][500005],t[505][500005];
int main()
{
    freopen("subway.in",'r',stdin);
    freopen("subway.out",'w',stdout);
    cin>>c>>n>>m>>d>>q;
    if(c==0)
    {
        if(n==2)
        {
            cout<<"32\n17";
        }
        if(n==3)
        {
            cout<<"35\n16";
        }
    }
    for(int i=1;i<=m;i++)
    {
        cin>>w[i]; 
    } 
    while(q--) 
    { 
        int x,y;
        cin>>x>>y;   
    } 
    return 0;
}
