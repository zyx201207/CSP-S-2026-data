#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int maxw(vector<int> v1)
{
    vector<vector<int>> num(33,vector<int> (n+1));
    vector<int> wei(33,0);
    for(int i=1;i<=n;i++)
    {
        int w=0;
        while(v1[i]>0)
        {
            if((v1[i]%2)==1)
            {
  //              cout<<i<<" "<<w<<endl;
                wei[w]++;
                num[w][i]=1;
            }
            v1[i]>>1;
            w++;
        }
    }
//    for(int i=0;i<=32;i++) cout<<wei[i]<<endl;
    int ans=1;
    int cheng=1<<32;
    vector<int> next(n+1);
    int id=1;
    for(int i=32;i>=0;i++)
    {

        if(wei[i]>=m)
        {
            for(int j=1;j<=n;j++)
            {
                if(num[i][j]==1)
                {
                    next[id]=v1[j];
                    id++;

                }
            }
            return 1<<i+maxw(next);
        }
    }
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    vector<int> v(n+2);
    vector<int> wei(33,0);
    vector<vector<int>> num(33,vector<int> (n+1));
    for(int i=1;i<=n;i++) cin>>v[i];
    cout<<maxw(v);



}

