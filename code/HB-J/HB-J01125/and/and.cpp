#include<bits/stdc++.h>
using namespace std;
int a[200001],b[200001],n,m,x=0,y=0;
int main()
{
    and.in>>n>>m;
    for(int i=0;i<n;i++)
    {
        and.in>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[j]>x){
                x=a[j];
                y=j;
            }
            a[y]=0;
        }
        b[i]=x;
    }
    and.out<<b[0];
}
