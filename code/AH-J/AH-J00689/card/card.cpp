#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
bool find1(vector<ll> a,ll t)
{
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==t)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int hash_t[m];
    vector<ll> cards(n);
    int ans[m];
    for(int i=0; i<m; i++)
    {
        ans[i]=0;
        hash_t[i]=0;
    }
    for(int i=0; i<n; i++)
    {
        cin>>cards[i];
    }


    for(int i=0; i<n; i++)
    {
        vector<ll> current(cards.begin()+i,cards.end());
        for(size_t j=i; j<n; j++)
        {

            if(hash_t[cards[j]]==1)
            {
                current.erase(find(current.begin(),current.end(),cards[j]),current.end());
            }
            current.push_back(cards[j]);
            hash_t[cards[j]]=1;
        }
        for(int k=1; k<=m; k++)
        {
            if(find1(current,k))
            {
                ans[k-1]++;
            }
        }
    }
    for(int i=0;i<m;i++){
       cout<<ans[i]<<' ';
    }
    return 0;
}
