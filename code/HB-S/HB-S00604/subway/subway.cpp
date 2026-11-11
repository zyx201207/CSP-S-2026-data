#include <bits/stdc++.h>
using namespace std;
struct WangXiaolu{
    int thst;
    int thti;
};
struct aa{
    int a;
    bool b;
};
int c,n,m,d,q,oll;
int drea[100002];
WangXiaolu lines[501],station[5000000],lation[501][500000];
bool feed[5000000]={0};
vector<int> ed;
aa sum;
void Hollow(int ch,int dqwz)
{
    sum.b=0;
    if(dqwz==drea[ch])
    {
        sum.a=sum.a+station[dqwz].thst;
        ed.push_back(sum.a);
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        bool flag=1;
        for(int j=1;j<=lines[i].thst;j++)
        {
            if(dqwz==lation[i][j].thst&&flag)
            {
                flag=0;
                j=1;
                continue;
            }
            if(!flag)
            {
                if((lation[i][j].thst==drea[ch]||station[lation[i][j].thst].thti>=2)&&!feed[lation[i][j].thst])
                {
                    sum.a+=lation[i][j-1].thti+lation[i][j].thti;
                    feed[lation[i][j].thst]=1;
                    Hollow(ch,lation[i][j].thst);
                    feed[lation[i][j].thst]=0;
                    sum.a-=lation[i][j-1].thti;
                    if(sum.b)
                    {
                        sum.b=0;
                        return ;
                    }
                }
                else
                {
                    if(j!=lines[i].thst)
                    continue;
                    sum.b=1;
                }
            }
        }
    }
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>station[i].thst;
        station[i].thti=0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>lines[i].thst;
        lines[i].thti=i;
        for(int j=1;j<=lines[i].thst;j++)
        {
            cin>>lation[i][j].thst>>lation[i][j].thti;
            station[lation[i][j].thst].thti++;
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>oll>>drea[i];
        feed[5000000]={0};
        feed[oll]=1;
        sum.a=station[oll].thst;
        Hollow(i,oll);
        cout<<"---------"<<ed[0]<<"---------"<<endl;
        sort(ed.begin(),ed.end());
        cout<<ed[0]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
