#include <bits/stdc++.h>
using namespace std;
std::vector<long long> arr;
bool cmp(long long a,long long b){return a>b;}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n=0,m=0;
    std::cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        long long x;
        std::cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end(),cmp);
    long long ans = arr[0];
    std::cout<<arr[0]<<' '<<arr[1];
    for(int i=1;i<m;i++)
    {
        ans&=arr[i];
    }
    std::cout<<ans<<std::endl;
    return 0;
}
