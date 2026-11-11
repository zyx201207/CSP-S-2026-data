#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.ans","w",stdout);
    int n,ans1;
    ans1=0;
    vector<long long>ans;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        long long a;
        char b;
        cin>>a;
        cin>>b;
        for (int j = 0; j < a; j++)
        {
            ans.push_back(b);
        }
    }
    int l,r;
    l=0;
    r=ans.size()-1;
    while (l<r)
    {
        if (ans[l]!=ans[r])
        {
            ans1++;
        }
        l++;
        r--;
    }
    cout<<ans1;
    return 0;
}