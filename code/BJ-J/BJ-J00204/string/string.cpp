#include<bits/stdc++.h>
using namespace std;
/*const int N=2e5+5;
int hashc(char c)
{
    return int(c-'a');
}
struct node{
    int c;
    int st;
    int en;
}a[N];
bool cmp(node k,node l)
{
    return (k.ed-k.st+1)>(l.ed-l.st+1);
}
struct use{
    int s,t;
    int c;
}u[N];*/
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    cout<<n-1;/*
    long long len=0;
    int sum=0;
    for(int y=1;y<=n;y++)
    {
        int num1;
        char c1;
        cin>>num1>>c1;
        c1=hashc(c1);
        a[y].st=len+1;
        len+=num1;
        a[y].en=len;
    }
    long long ans=0;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(u[j].c!=a[i].c)
            {
                ans+=min(u[j].en,a[i].en)-max(u[j].st,a[i].st)+1;
            }
        }
    }*/
    return 0;
}