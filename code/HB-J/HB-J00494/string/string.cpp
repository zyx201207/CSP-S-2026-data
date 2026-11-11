#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long num,total,zwz;
    string s,zwz_string,left,right;
    vector<string> data;
    for(int i = 0;i<n;i++)
    {
        cin>>num>>s;
        total+=num;
        for(int i = 0;i<num;i++)
        {
            data.push_back(s);

        }
    }
    if(total%2!=0)
    {

        zwz = (total+1)/2-1;
    }

//    for(int i = 0;i<data.size();i++)
//    {
//        cout<<data[i];
//    }
    return 0;
}
