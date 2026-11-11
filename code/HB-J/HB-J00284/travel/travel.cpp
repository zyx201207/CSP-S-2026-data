#include <bits/stdc++.h>
using namespace std;

int c1 , c2;
string s1 , s2;
int ans1 , ans2 , ans3 , ans4;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2)//1
    {
        ans1 = 1;
        int p1 = 0, p2 = 0;
        for(int i = 0 ; i <= 1 ; i ++)
        {
            p1 = p1 * 10 + int(s1[i] - '0');
            p2 = p2 * 10 + int(s2[i] - '0');
        }
        cout << p1 <<" "<< p2 <<"\n";
        if(p1 == p2)//2
        {
            ans2 = 1;
            if((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C'))//3 4
            {
                ans3 = 1;
                if(abs(s1[2] - s2[2]) == 1 || (s1[2] > 'C' && s2[2] > 'C'))
                {
                    ans4 = 1;
                }
                else
                {
                    ans4 = 0;
                }
            }
            else ans3 = ans4 = 0;
        }
        
    }
    else
    {
        ans1 = ans2 = ans3 = ans4 = 0;
    }
    printf("%d%d%d%d", ans1 , ans2 , ans3 , ans4);
    return 0;
}