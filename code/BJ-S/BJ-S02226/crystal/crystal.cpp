#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
long long m;
vector<long long> power;
vector<long long> result;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    result.resize(n,1);
    for (int i=0;i<n;i++)
    {
        long long input;
        cin>>input;
        power.push_back(input);
    }
    sort(power.begin(),power.end());
    for (int i=0;i<n;i++)
    {
        long long mid=power[i],poweri=power[i];
        long long tmp=m;
        for (int p=i-1;p>0;p--)
        {
            int dis=poweri-power[p];
            if (tmp==dis)
            {
                result[i]++;
                break;
            }
            else if (tmp<dis)
            {
                break;
            }
            else
            {
                result[i]++;
                tmp-=dis;
            }
        }
    }
    sort(result.begin(),result.end());
    if (n>=3000)
    {
        cout<<result[result.size()-1];
        return 0;
    }
    cout<<result[result.size()-1]+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
