#include <bits/stdc++.h>
using namespace std;

string c1,c2,s1,s2;

void init()
{
    cin >> c1 >> s1 >> c2 >> s2;
}

int my_abs(int x)
{
    if(x < 0) return -x;
    return x;
}

void work()
{
    bool q1 = 0;
    bool q2 = 0;
    bool q3 = 0;
    bool q4 = 0;

    if(c1 == c2)
        q1 = 1;

    q2 = q1;
    string t,t2;
    t = s1.substr(0,2);
    t2 = s2.substr(0,2);

    // cout << t << " " << t2 << endl;

    if(t == t2)
        q2 &= 1;
    else 
        q2 = 0;

    q3 = q1 & q2;
    long long seata = 0;
    long long seatb = 0;

    seata = s1[2] - 'A';
    seatb = s2[2] - 'A';

    // cout << seata << " " << seatb << endl;
    
    if(seata < 3 && seatb < 3)
        q3 &= 1;
    else if(seata >= 3 && seatb >= 3)
        q3 &= 1;
    else
        q3 = 0;
    // cout << q3 << endl;

    q4 = q1 & q2;
    q4 &= q3;

    // cout << seata << " " << seatb << " ";
    // cout << my_abs(seata - seatb) << endl;
    if(my_abs(seata - seatb) <= 1)
        q4 &= 1;
    else
        q4 = 0;

    cout << q1 << q2 << q3 << q4 << endl;

}

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    init();
    work();
    return 0;
}