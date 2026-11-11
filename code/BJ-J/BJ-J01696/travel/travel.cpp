#include <iostream>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s,s1,c,c1;
    cin >>s >>s1 >> c >>c1;
    if (s == c) cout << 1;
    else{
        cout << "0000" << endl;
        return 0;
    }
    bool flag = false;
    int t = 0,t1 = 0;
    if (s1[0] == '0');
    {
        t = (s1[1] - '0');
        flag = true;
    }
    if (flag == false)
    {
        t = (s1[0]- '0') * 10 + (s1[1] - '0');
    }
    flag = false;
    if (c1[0] == '0');
    {
        t1 = (c1[1] - '0');
        flag =  true;
    }
    if (flag == false){
        t1 = (c1[0]- '0') * 10 + (c1[1] - '0');
    }
    if (t == t1)
    {
        cout <<1;
    }
    else
    {
        cout <<"000"<<endl;
        return 0;
    }
    char k = s1[2],k1 = c1[2];
    if ((k == 'A' || k == 'B' || k == 'C') && (k1 == 'A' || k1 == 'B' || k1 == 'C'))
    {
        cout << 1;
    }
    else if ((k1 == 'D' || k1 == 'F') && (k == 'D' || k == 'F'))
    {
        cout << 1;
    }
    else
    {
        cout <<"00"<< endl;
        return 0;
    }
    if ((k == 'A' && k1 == 'B') || (k == 'B' && k1 == 'C') || (k == 'D'|| k1 == 'E'))
    {
        cout <<1;
    }
    else cout <<"0"<<endl;
    return 0;
}
