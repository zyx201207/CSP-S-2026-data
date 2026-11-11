#include <iostream>
#include <bits/stdc++.h>

using namespace std;
string rjz(int a)
{
    string s;
    while(a!=0)
    {
        s+=a%2+'0';
        a/=2;
    }
    reverse(s.begin(),s.end());
    return s;
}
int dfs(int n,int m,int pos,int j)
{
    if(pos>n)
        return 0;
    if(j>m)
        return pos;
    for(int i=0;i<n-j;i++)
    {
        if(dfs(n,m,pos+i,j+1)==0)
            return 0;
        else if(dfs(n,m,pos+i,j)==pos+i)
            return pos;
    }

}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout << a[3];
    return 0;
}
