#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,s;
bool judge(int d,int a1,int a2,int a3,int a4)
{
    if(a4-a1 <= 2*d&&a2-a1 < d&&a3 - a1 <= d&&a4 - a2 <=d&&a4-a3<=d&&a4-a1>d)
        return true;
    else
        return false;
}
int la[2000000] = {0};
int main ()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> c >> t;
    for(int o = 0; o < t; o++)
    {
        int ans = 0;
        cin >> n >> s;
        for(int i =0 ; i < n; i++)
            cin >> la[i];
        if(n<4)
        {
            cout << "0"<<endl;
        }
        else
        {
            for(int i =0 ; i < n-3; i++)
                if(judge(s,la[i],la[i+1],la[i+2],la[i+3]))
                    ans++;
            cout << ans << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
