#include <bits/stdc++.h>
using namespace std;
int b, lines, stations, mostsub, plans;
int pos_now, pos_tar;
int station_time[500005];
struct subway
{
    int lines_howmuch;
    int lines_station[1005];
    int lines_time[1005];
}sub[505];
int ischange(int line1, int line2)
{
    if(line1 == line2) return 1e8;
    int j = 0;
    int ans = 1e8;
    for(int i = 0; i < sub[line1].lines_howmuch; i++)
    {
        while(j < sub[line2].lines_howmuch && sub[line1].lines_station[i] > sub[line2].lines_station[j]) j++;
        if(sub[line1].lines_station[i] == sub[line2].lines_station[j])
        {
            ans = max(ans, sub[line1].lines_time[i] + sub[line2].lines_time[j]);
        }
    }
    return ans;
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> b >> lines >> stations >> mostsub >> plans;
    for(int i = 1; i <= stations; i++) cin >> station_time[i];
    for(int i = 1; i <= lines; i++)
    {
        cin >> sub[i].lines_howmuch;
        for(int j = 1; j <= sub[i].lines_howmuch; j++)
        {
            cin >> sub[i].lines_station[j] >> sub[i].lines_time[j];
        }
    }
    for(int k = 0; k < plans; k++)
    {
        cin >> pos_now >> pos_tar;
        int ans = station_time[pos_tar] + station_time[pos_now];
        for(int i = 0; i < lines; i++)
        {
            for(int j = 0; j < sub[i].lines_howmuch; j++)
            {
                if(sub[i].lines_station[j] == pos_tar) ans += sub[i].lines_time[j];
                if(sub[i].lines_station[j] == pos_now) ans += sub[i].lines_time[j];
            }

        }
        cout << ans <<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
