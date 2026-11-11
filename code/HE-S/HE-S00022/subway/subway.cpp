#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 500005;
long long c,lines,stations,max_passes,questions,tmp1,tmp2,l,r;
long long entrances[N],k[N],exits[21][50005];
int routes = 0;
long long line_stations[21][50005];
//vector < pair<long long,long long> > graphs[N]; I give up.gif
int dfs(int begins,int ends)
{
    int cur_line[21],target_line[21];
    //for(vector<long long>::iterator it = line_stations.begin();it != line_stations.end();it++)
    for(int i = 1;i <= lines;i++)
    {
        for(int j = 1;j <= k[i];j++)
        {
            if(line_stations[i][j] == begins)
            {
                cur_line[i] = 1;
            }
            else if(line_stations[i][j] == ends)
            {
                target_line[i] = 1;
            }
        }
    }
    //cout << cur_line << " " << target_line << endl;
    for(int i = 1;i <= lines;i++)
    {
        if(cur_line[i] == target_line[i])
        {
            return exits[cur_line[i]][begins] + exits[target_line[i]][ends];
        }
    }
    for(int a = 1;a <= lines;a++)//interchange
            {
                for(int b = 1;b <= lines;b++)
                {
                    if(cur_line[a] && target_line[b])
                    {
                        for(int i = 1;i <= k[a];i++)
                        {
                            for(int j = 1;j <= k[b];j++)
                            {
                                if(line_stations[a][i] == line_stations[b][j])
                                {
                                    return exits[a][begins] + exits[a][line_stations[a][i]] + dfs(line_stations[a][i],ends);
                                }
                            }
                        }
                    }
                }
            }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> lines >> stations >> max_passes >> questions;
    for(int i = 1;i <= stations;i++)//points_value
    {
        cin >> entrances[i];
    }
    for(int i = 1;i <= lines;i++)//lines_value
    {
        cin >> k[i];
        for(int j = 1;j <= k[i];j++)
        {
            cin >> tmp1 >> tmp2;//end,value
            //line_stations[i].push_back(tmp1);
            exits[i][tmp1] = tmp2;
            line_stations[i][j] = tmp1;
        }
    }
    for(int i = 1;i <= questions;i++)
    {
        cin >> l >> r;//LET'S GO!!! try to get 12 points.png
        //I think failed:(
        long long ans = entrances[l] + entrances[r];//first stations value
        //and then ++ to lines value
        routes = dfs(l,r);
        ans += routes;
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
