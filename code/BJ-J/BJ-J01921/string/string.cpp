#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int rep[MAXN];
char ch[MAXN];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {

        cin>>rep[i]>>ch[i];
    }
    long long lp=0,rp=0;//number of matched characters to the left and right
    long long ll=1,rl=n;//the index for the next batch to match (not yet matched)
    long long countc=0;//ans
    while(ll<rl)
    {

        //cout<<ll<<" "<<rl<<" "<<ch[ll]<<" "<<ch[rl]<<" "<<rep[ll]<<" "<<rep[rl]<<"\n";
        if(ch[ll]!=ch[rl])
        {
            countc+=min(rep[ll],rep[rl]);


        }
        long long del=min(rep[ll],rep[rl]);
        lp+=del;
        rp+=del;
        rep[ll]-=del;
        rep[rl]-=del;
        if(rep[ll]==0)
        {

            ll++;
        }
        if(rep[rl]==0)
        {

            rl--;
        }

    }
    cout<<countc;
}
