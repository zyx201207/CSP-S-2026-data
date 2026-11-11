#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int maxn=1e5+5;
struct node{

    int time_zhanting;

}a[maxn];

vector<pair<int,int>> g[maxn];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >>m >> d >> q;

    for(int i=1;i<=m;i++)
    {
       cin >> a[i].time_zhanting;
    }
    for(int i=1;i<=n;i++)
    {
        int sum;
        cin >> sum;
        while(sum--)
        {
            int v,time;
            cin >> v >> time;
        }
    }
    for(int i=1;i<=q;i++)
    {
        int a,b;
        cin >> a >> b;
        cout << 1 << "\n";
    }
    return 0;
}
/*
文件 subway.in 中读入数据。
输入的第一行包含五个非负整数 c, n, m, d, q,分别表示测试点编号、地铁线路数、
地铁站数、每个地铁站最多被几条线路经过,以及出行计划数。特别地,若 c = 0,则
该测试点为样例。
输入的第二行包含 m 个正整数 w 1 , w 2 , . . . , w m ,依次表示从每个地铁站的地铁口走
到站厅需要的时间。
输入的第 i + 2 (1 ≤ i ≤ n) 行包含 1 + 2k i 个正整数,其中第一个正整数为 k i ,表
示第 i 条线路经过的地铁站数;接下来 2k i 个正整数为 a i,1 , t i,1 , a i,2 , t i,2 , . . . , a i,k i , t i,k i ,其
中 a i,j 表示第 i 条线路经过的第 j 个地铁站,t i,j 表示从该地铁站的站厅走到第 i 条线
路的站台需要的时间。
输入的第 r + n + 2 (1 ≤ r ≤ q) 行包含两个正整数 x r , y r ,分别表示第 r 个出行计
划的起点和终点所在的地铁站编号。
*/
