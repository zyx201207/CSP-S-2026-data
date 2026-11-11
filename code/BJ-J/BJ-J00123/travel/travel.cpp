#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,p1,p2;
char t1,t2;
int f[135];
bool check()
{
    if(c1!=c2||p1!=p2)
        return 0;
    if(t1=='A')
        return (t2=='B');
    if(t1=='B')
        return (t2=='A'||t2=='C');
    if(t1=='C')
        return (t2=='B');
    if(t1=='D')
        return (t2=='F');
    if(t1=='F')
        return (t2=='D');
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    f['A']=1,f['B']=1,f['C']=1,f['D']=2,f['F']=2;
    p1="",p1+=s1[0],p1+=s1[1],t1=s1[2];
    p2="",p2+=s2[0],p2+=s2[1],t2=s2[2];
    printf("%d%d%d%d\n",(c1==c2),(c1==c2&&p1==p2),(c1==c2&&p1==p2&&f[t1]==f[t2]),check());
    return 0;
}
