#include<bits/stdc++.h>
using namespace std;
int n,a[10000],b[10000],s[1000000],ans,num;
int main()
{
    freopen('travel.in','r',stdin);
    freopen('travel.out','w',stdout);

    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i] >> b[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=ans;j<ans+a[i];j++)
        {
            s[j]=b[i];
        }
        ans+=a[i];
    }
    for(int i=0;i<ans;i++)
    {
        if(s[i]!=s[n-1-i]) num+=1;
    }
    cout << num;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
