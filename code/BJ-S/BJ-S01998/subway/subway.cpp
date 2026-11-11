/*
    16:30 zen me hai you liang ge xiao shi a
    ta men zen me dou zai xie dai ma
    wo pang bian de ren hao xiang zai xie di san ti
    nan dao qi ta ren dou hui zuo ma?..
    jue wang
    wo hao cai(T.T)
    zhen de hao lei a






    bei jing ba zhong si cun xiao qu huan ying nin!
    zhe li you mei wei(?)de shi tang,you qu(?)de ke cheng,feng(zao) fu(gao) duo(tou) cai(ding) de ti(zi) yu(ran) huo(ti) dong(yu)
    su zhi ban e wai zeng song wan duan lian da li bao!


    xue xiao wo tao yan ni.
*/
#include <bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
int w[M];
struct node
{
    int s,t;
};
vector<node> a[N];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        for(int j=1;j<=x;j++) cin>>a[i][j].s>>a[i][j].t;
    }
    while(q--)
    {
        int f,l;
        cin>>f>>l;
        cout<<w[f]+w[l]<<endl;
    }
    return 0;
}


























































































































































































































































































//33499
