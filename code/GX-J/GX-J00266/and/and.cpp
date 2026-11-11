#include <bits/stdc++.h>
using namespace std;

int and(int a;int b)
{
    int x=a,y=b,cnt1=0,cnt2=0;
    char a1[15],b1[15],a2[15],b2[15];
    for(int i=1;x!=0;i++)
    {
        a1[i]=x%2;
        x/=2;
        cnt1++
    }
    for(int i=1;y!=0;i++)
    {
        a1[i]=y%2;
        y/=2;
        cnt2++;
    }
    int cnt3=cnt1,cnt4=cnt2;
    for(int i=1;i<=cnt1;i++)
    {
        a2[i]=a1[cnt3];
        cnt3--;
    }
    for(int i=1;i<=cnt2;i++)
    {
        a2[i]=a1[cnt4];
        cnt4--;
    }

}

int main()
{
    int a=15,b=12;
    cout << a & b;
    return 0;
}
