#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> c1 >> s1 >> c2 >> s2;
    int num1=0,num2=0;
    int level1=s1[2]-'A'+1;
    int level2=s2[2]-'A'+1;
    for(int i=0;i<2;i++) num1=num1*10+s1[i]-'0';
    for(int i=0;i<2;i++) num2=num2*10+s2[i]-'0';
    if(c1==c2) cout << 1;
    else cout << 0;
    if(c1==c2&&num1==num2) cout << 1;
    else cout << 0;
    if(c1==c2&&num1==num2&&(1<=level1&&level1<=3&&1<=level2&&level2<=3||4<=level1&&level1<=5&&4<=level2&&level2<=5)) cout << 1;
    else cout << 0;
    if(c1==c2&&num1==num2&&(1<=level1&&level1<=3&&1<=level2&&level2<=3||4<=level1&&level1<=5&&4<=level2&&level2<=5)&&abs(level1-level2)==1) cout << 1;
    else cout << 0;
    return 0;
}
