#include<bits/stdc++.h>
using namespace std;
int r,x,a[5];
string r1,x1;
int main()
{
    cin>>r>>r1>>x>>x1;
    if(r==x)
        a[1]=1;
    if(r1[0]==x1[0]&&r1[1]==x1[1])
        a[2]=1;
    if(((r1[2]==A||r1[2]==B||r1[2]==C)&&(x1[2]==A||x1[2]==B||x1[2]==C))||((r1[2]==D||r1[2]==E)&&(x1[2]==D||x1[2]==E)))
        a[3]=1;
    if(r1[2]==A&&x1[2]==B||r1[2]==C)
}
