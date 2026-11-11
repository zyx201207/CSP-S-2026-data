#include<bits/stdc++.h>
using namespace std;
vector<int> a;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);


    int n,m,ans1=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {

        cin>>a[i];
    }
    for(int j=0;j<n;j++)
    {
        int ans=a[j];


        for(int i=1;i<m;i++)
        {

            ans=ans&a[i];
        }
        if(ans1<ans)
        {

            ans1=ans;
        }
    }
    cout<<ans1;

    return 0;

}
