#include <iostream>
#include <cstdio>
using namespace std;
int islands[2000005],visited[2000005];
int nums,energies,ans = 0,min_chance = 114514,val = 0;
void dfs(int begins,int ends,int chance)//b -> e;
{
    if(islands[ends] - islands[begins] <= energies)// still one step to AC.png
    {
        if(chance > min_chance)//too much!
        {
            return;
        }
        ans++;
        return;
    }
    visited[begins] = 1;
    int target = begins + 1;
    for(int i = target;i <= ends;i++)// b -> i
    {
        if(islands[i] - islands[begins] > energies)
        {
            break;
        }
        dfs(i,ends,chance + 1);
    }
    return;
}
int get_min(int begins,int ends)//get min_chance
{
    int cur = islands[begins];
    int target = islands[ends];
    if(islands[ends] - islands[begins] <= energies)
    {
        return 1;//get!
    }
    for(int i = ends;i > begins;i--)
    {
        if(islands[i] - islands[begins] <= energies)
        {
            return get_min(i,ends) + 1;
        }
    }

    return 0;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--)// try to getting 8 points.png
    {
        val = 0;
        cin >> nums >> energies;
        for(int i = 1;i <= nums;i++)
        {
            cin >> islands[i];
        }
        for(int i = 1;i <= nums - 1;i++)
        {
            for(int j = i + 1;j <= nums;j++)//i <-> j?
            {
                ans = 0;
                min_chance = get_min(i,j);
                //cout << i << "to" << j << " " << min_chance << endl;
                dfs(i,j,0);
                if(ans == 2)
                {
                    val++;
                }
            }
        }
        cout << val << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
