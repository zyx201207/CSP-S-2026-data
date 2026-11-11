//GZ-J00661
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int a[5];
int main()
{
    int c1,c2;
    string s1,s2;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    char sit1=s1[2];
    char sit2=s2[2];
    if(c1!=c2)
    {
        printf("0000");
        return 0;
    }
    if(s1[0]!=s2[0]||s1[1]!=s2[1])
    {
        printf("1000");
        return 0;
    }
    if((sit1<'D'&&sit2>'C')||(sit1>'C'&&sit2<'D'))
    {
        printf("1100");
        return 0;
    }
    if(sit1>'C'&&sit2>'C')
    {
        printf("1111");
    }
    else
    {
        if(abs(sit1-sit2)==1)
            printf("1111");
        else
            printf("1110");
    }
    return 0;
}
