#include <bits/stdc++.h>
using namespace std;
int c1,c2;
char a,b,c,d,e,f;
char o1,o2,o3,o4,o5;
string z1,z2;
int ans[10]={0};
int main(){
    o1='A',o2='B',o3='C',o4='D',o5='F';
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1;
    cin >> a >> b >> c;
    cin >> c2;
    cin >> d >> e >> f;
    if (c1==c2){
        ans[1]=1;
    }
    if (a+b==d+e)
    {
        ans[2]=1;
        if (c==o1 || c==o2 || c==o3)
        {
            if (f==o1 || f==o2 || f==o3)
            {
                ans[3]=1;
            }
        }
        else
        {
            if (f==o4 || f==o5)
            {
                ans[3]=1;
            }
        }
    }
    if (a+b==d+e)
    {
        if (c==o1)
        {
            if (f==o2) ans[4]=1;
        }
        if (c==o2){
            if (f==o1 || f==o3) ans[4]=1;
        }
        if (c==o3){
            if (f==o2) ans[4]=1;
        }
        if (c==o4)
        {
            if(f==o5) ans[4]=1;
        }
        if (c==o5)
        {
            if(f==o4) ans[4]=1;
        }
    }
    for (int i=1;i<=4;i++)
    {
        cout << ans[i];
    }

}
