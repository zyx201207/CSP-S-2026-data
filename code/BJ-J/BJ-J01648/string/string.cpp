#include<iostream>
using namespace std;
int main()
{
    freopen("string.in","r",stdin)
    freopen("string.out","w",stdout);
    int n,a[200005],num=0;
    char s[200005];
    string q;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] >> s[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            q+=s[i];
        }
    }
    for(int i=0;i<=(q.length()-1)/2;i++)
    {
        if(q[i]!=q[q.length()-1])
        {
            num++;
        }
    }
    cout << num;
}