#include <bits/stdc++.h>
using namespace std;
#define test 3
#define pii pair<int,int>
long long pos[1000050];
int mem[5005][5005][2];
long long n,dst;
pii operator+(pii a,pii b)
{
    //cout<<a.first<<' '<<a.second<<' '<<b.first<<' '<<b.second<<"in add\n";
    if(a.second==-1)return b;
    if(a.second==b.second){/*cout<<"add1\n";*/return {a.first+b.first,a.second};}
    if(a.second<b.second){/*cout<<"add2\n";*/return {a.first,a.second};}
    /*cout<<"add3\n";*/
    return b;
}
pii dfs(int st,int ed)//paths,dis
{
    if(st==ed)return {1,0};
    if(ed<5005&&mem[st][ed][0]!=-1)return {mem[st][ed][0],mem[st][ed][1]};
    pii ans={0,-1};
    for(int i=st+1;i<=ed&&pos[i]-pos[st]<=dst;i++)
        {/*cout<<i<<" in "<<st<<"to"<<ed<<endl;*/ans=ans+dfs(i,ed);}
    /*cout<<ans.first<<' '<<ans.second<<" from "<<st<<"to"<<ed<<endl;*/
    if(ed<5005) mem[st][ed][0]=ans.first,mem[st][ed][1]=ans.second+1;
    return {ans.first,ans.second+1};
}
int main()
{
    #ifdef test
     freopen("migrate.in","r",stdin);
     freopen("migrate.out","w",stdout);
    #endif // test
    int c;
    int t;
    cin>>c>>t;
    while(t--)
    {
        memset(mem,-1,sizeof(mem));
        cin>>n>>dst;
        long long cnt=0;
        for(int i=1;i<=n;i++)cin>>pos[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=i+3;j<=n;j++)
                if(dfs(i,j).first==2)cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
/*
16
9
7
12
0
0
0
2
1
0
2
3
6
0
2
0*/
