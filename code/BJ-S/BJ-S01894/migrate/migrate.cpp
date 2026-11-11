/*idea:
for every island, the minimum number of moves to get there will be recorded,
as well as the number of ways that can achieve that minimum
and calculate the next by dp

note: we don't care about precisely how many ways there are, we just care about
if it is more than 2
so if we find 3 ways to get to somewhere, we don't need to continue
*/


/*
hang on...
the start and finish islands can be in the middle
so it is more regional dp
a region will be selected (in short-long order), and the result will be calculated by dp
*/
/*
what i'll do:
if it is a special case then I'll tey with something else to get some points
    */
#include<bits/stdc++.h>
using namespace std;
int ij;
const int MAXN=10005;
long long pos[MAXN];
unsigned long long len[MAXN][MAXN];
unsigned long long ways[MAXN][MAXN];
//long long delay[MAXN];
void round()
{
    long long n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>pos[i];
    }
    long long cnt=0;
    for(int w=0;w<=n;w++)
    {
        //jisuan
        for(int i=1;i+w<=n;i++)
        {
            /*for(int l=1;l<=10000*pow(100,(w>2));l++)
            {

                memset(delay,0,sizeof(delay));
            }*/
            //cout<<i<<"-"<<i+w<<": ";
            len[i][i+w]=INT_MAX;
            ways[i][i+w]=0;
            if(w==0){
                    len[i][i]=0;
            ways[i][i]=1;
            }
                else if(pos[i+w]-pos[i]<=d)
                {

                    len[i][i+w]=1;
                    ways[i][i+w]=1;
                }
            else
            {
                    len[i][i+w]=ULLONG_MAX;
                    ways[i][i+w]=0;
                for(int j=i+1;j<i+w;j++)
                {

                    if(len[i][j]!=ULLONG_MAX&&len[j][i+w]!=ULLONG_MAX)
                    {
                        if(len[i][j]+len[j][i+w]<len[i][i+w])
                        {

                            ways[i][i+w]=1;
                            len[i][i+w]=len[i][j]+len[j][i+w];
                        }
                        else if(len[i][j]+len[j][i+w]==len[i][i+w])
                        {
                            ways[i][i+w]+=ways[i][j]*ways[j][i+w];
                        }
                        //cout<<j<<"->"<<ways[i][i+w]<<" "<<len[i][i+w]<<"\n";
                    }

                }
            }
            if(ways[i][i+w]==2)
                {

                    cnt++;
                }
            //cout<<ways[i][i+w]<<" "<<len[i][i+w]<<"\n";
        }
    }
    //cout<<cnt<<"\n";
}
void sp()
{
    long long n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        
        cin>>pos[i];
        
    }
    int diff=pos[1]-pos[0];
    if(diff<3*d&&diff>=2*d)
    {
        
        cout<<n-3<<"\n";
    }
    else{
        cout<<"0\n";
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>ij;
    int t;
    cin>>t;
    if(ij==11||ij==12)
    {
        
        //dengchashulie
        for(int i=1;i<=t;i++)sp();
    }
    for(int i=1;i<=t;i++)
    {

        round();
    }
}
