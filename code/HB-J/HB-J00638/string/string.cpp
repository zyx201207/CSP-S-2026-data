#include <bits/stdc++.h>
using namespace std;
int main()
{

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,m,step=0;
    char sum;
    vector<char> data;
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>m>>sum;
        for(long long j=1;j<=m;j++)
        {
            data.push_back(sum);
        }
    }
    long long k=data.size();
    for(long long i=0;i<k/2;i++)
    {
        long long r=k-i-1;
        if(data[i]==data[r])
        {
            continue;
        }
        data[r]=data[i];
        step++;
    }
    cout<<step<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
