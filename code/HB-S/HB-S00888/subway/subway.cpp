#include<bits/stdc++.h>
using namespace std;
struct stations
{
    int line;
    int num;
    int ti;
};
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,num = 1;
    cin>>c>>n>>m>>d>>q;
    vector<int> w(m);
    stations sta[500001];
    for(int i = 0;i<m;i++)
    {
        cin>>w[i];
    }
    for(int i = 0;i<n;i++)
    {
        int ki;
        cin>>ki;
        for(int j = 1;i<=ki;j++)
        {
            cin>>sta[num].num>>sta[num].ti;
            sta[num].line = i;
        }
    }
    return 0;
}
