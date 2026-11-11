#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.ans","w",stdout);
    vector<int>ans;
    vector<int>ans1;
    ans.push_back(0);
    int a,b;
    cin>>a>>b;
    for (int i = 0; i < a; i++)
    {
        int c;
        cin>>c;
        ans[i+1]=ans[i] and c;
    }
    for (int i = 0; i < a; i++)
    {
        for (int i1 = 0; i1 < a+1; i1++)
        {
            if (i1-i==b)
            {
                ans1.push_back(ans[i1]-ans[i]);
            }
        }
    }
    sort(ans1.begin(),ans1.end());
    reverse(ans1.begin(),ans1.end());
    cout<<ans[0];
    return 0;
}