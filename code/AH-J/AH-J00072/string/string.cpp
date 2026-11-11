#include<bits/stdc++.h>
using namespace std;
int n;
string yuan;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int ci=0;
    cin>>n;
    vector<int>wei(n);
    vector<char> zifu(n);
    for(int i=0;i<n;i++)
    {
        int a;
        char b;
        cin>>a;
        wei.push_back(a);
        cin>>b;
        zifu.push_back(b);
    }
    int yuanwei=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<wei[i];j++){
            yuan[yuanwei]=zifu[i];
            yuanwei++;
        }
    }
    for(int i=1;i<=yuanwei/2+1;i++)
    {
        if(yuan[i]!=yuan[yuan.size()+1-i])
        {
            ci++;
        }
    }
    cout<<ci;
    return 0;
}
