#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
char ch[10000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n,x,ed=0,cnt=0;
    char c;
    cin>>n;
    while(n--)
    {
        cin>>x>>c;
        while(x--)
        {
            ch[++ed]=c;
        }

    }
    for(int i=1;i<=ed/2;++i)
    {
        if(ch[i]!=ch[ed+1-i])cnt++;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

