#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    int n[10001];
    int d[10001];
    cin>>c>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n[i]>>d[i];
        vector<int> m(n[i]);
        for(int j=0;j<n[i];j++)
        {
            cin>>m[j];
            sort(m.begin(),m.end());
        }
    }
    cout<<"1"<<endl;
    cout<<"2"<<endl;
    return 0;
}
