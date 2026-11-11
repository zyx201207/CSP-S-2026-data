#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main ()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    string ans;
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
        string l;
        cin >> l;
        for (int j=1;j<=a[i];j++)
            ans+=l;
    }
    int sum=ans.length();
    int j=sum-1;
    int num=0;
    for (int i=0;i<sum/2;i++)
    {
        if (ans[i]!=ans[j])
            num++;
        j--;
    }
    cout << num;
    return 0;
}
