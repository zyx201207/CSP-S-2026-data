#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
char h;
string s;
int main()
{
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    int y[c]={0};
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        cin>>h;
        for(int j=b;j<a+b;j++)
        {
            c++;
            y[i]=y[i]-'a';
        }
    }
    for(int i=0;i<c;i++)
    {

        cout<<char(y[i]+'a');
    }
    return 0;
}
