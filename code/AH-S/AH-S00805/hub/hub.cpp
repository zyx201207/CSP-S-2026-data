#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int c,T;
    cin>>c>>T;
        while(T--)
        {
            int n,k;
            cin>>n>>k;
            for(int i=1;i<n;i++)
            {
                int aaa,bbb;
                cin>>aaa>>bbb;
            }
            int num=(n+1)/2+1;
            int ans=0;
            if(num<=k&&k<n)
                ans=1;
            else if(k==n)
                ans=0;
            else if(num/k==1)
                ans==2;
            else
                ans=num/k;
            cout<<ans<<'\n';
        }
    return 0;
}

