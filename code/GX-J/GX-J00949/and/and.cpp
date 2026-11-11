#include <bits/stdc++.h>
using namespace std;
bool z(int a,int b)
{
    if(a>b) return a;
    else return b;
}
int main()
{
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int a,b;
    cin>>a>>b;
    int p[a];
    for(int i=0;i<a;i++)
    {
        cin>>p[i];
    }
    sort(p,p+a,z);
    /*for(int i=0;i<b;i++)
    {
        while(p[i]>0)
        {
            r[i]=p[i]%2+r;
            p[i]/=2;
        }
    } */
    cout<<p[b-b];
	return 0;
}

