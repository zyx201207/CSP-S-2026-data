#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main()
{
    long long c,n,m,d,q;
    vector<int> times;
    cin>>c>>n>>m>>d>>q;

    for(int i=1;i<=m;i++)
    {
        long long a1;
        cin>>a1;
        times.push_back(a1);
    }

    for(int i=1;i<=m;i++)
    {
        long long a2;
        cin>>a2;
        times.push_back(a2);
    }


    return 0;
}
