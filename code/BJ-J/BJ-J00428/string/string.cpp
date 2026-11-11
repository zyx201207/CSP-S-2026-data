#include <iostream>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin>>n;
    string s;
    long long lot=0;
    for(int i=1;i<=n;i++)
    {
        long long a;
        cin>>a;
        char b;
        cin>>b;
        for(int j=lot;j<lot+a;j++)
        {
            s[j]=b;
        }
        lot=lot+a;
    }
    long long right=0;
    long long left=s.size()-1;
    long long change=0;
    while(right!=left||left<right)
    {
        if(s[right]!=s[left])
        {
            change=change+1;
        }
        right++;
        left--;
    }
    cout<<change;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
