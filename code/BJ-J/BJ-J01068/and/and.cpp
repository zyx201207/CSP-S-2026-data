#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+10;
int n,m,a[maxn],ans;
int num[maxn][40];
vector<int> pos;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        int x=a[i],l=0;

        while(x>0)
        {
            num[i][35-l]=x%2;
            x/=2;l++;
        }
    }

    for(int i=1; i<=n; i++)
        pos.push_back(i);

    for(int j=0; j<=35; j++)
    {
        vector<int> s;

        for(int i:pos)
        {
//            cout<<num[i][j];
            if(num[i][j])
                s.push_back(i);
        }
//        cout<<"    "<<pos.size()<<endl;

        if(s.size()>=m)
        {
            pos=s;
            int cnt=a[pos[0]];

            for(int i=0; i<m; i++)
                cnt&=a[pos[i]];
            ans=max(ans,cnt);
        }
    }
    cout<<ans<<endl;

    return 0;
}
