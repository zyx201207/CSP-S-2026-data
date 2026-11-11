#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main()
{
    long long n,m;
    cin>>n>>m;
    vector<long long> ai;
    set<long long> aI;
    for(int i=1;i<=n;i++)
    {
        long long a;
        cin>>a;
        ai.push_back(a);
    }


    for(int j=0;j<=m-1;j++)
    {
        for(int y=0;y<=m-1;y++)
        {
            if(ai[y]!=ai[y+1])
            {
                ai[y] += 1;
                break;
            }
        }

    }

    for(int h=0;h<=n-1;h++)
    {
        aI.insert(ai[h]);
    }


    cout<<ai.size()-aI.size()+1;




    return 0;
}
//5 8
//-3 -1 2 2 7

