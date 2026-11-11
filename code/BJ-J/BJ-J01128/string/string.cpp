#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,num;
    cin>>n;
    string sz,s;
    for(int i=0;i<n;i++)
    {
        cin>>num>>s;
        for(int j=0;j<num;j++){
            sz+=s;
        }
    }
    int ans=0;
    int mid=0;
    if(sz.size()%2==0){
        mid=sz.size()/2-1;
        for(int i=0,j=sz.size()-1;j>=mid;i++,j--){
                cout<<i<<j;
            if(sz[i]!=sz[j])
                ans++;
        }
    }
    if(sz.size()%2==1){
        mid=sz.size()/2;
        //cout<<sz.size();
        for(int i=0,j=sz.size()-1;j>=mid;i++,j--){
               // cout<<1;
            if(sz[i]!=sz[j])
                ans++;
        }
    }
    cout<<ans;
}
