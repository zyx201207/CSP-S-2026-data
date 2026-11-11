#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
char t1,t2;
char a[85];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>t1>>c2>>s2>>t2;
    a['A']=a['B']=a['C']=1;
    cout<<(c1==c2)<<(c1==c2&&s1==s2)<<(c1==c2&&s1==s2&&a[t1]==a[t2])<<(c1==c2&&s1==s2&&a[t1]==a[t2]&&(t1=='B'||t2=='B'||(a[t1]==0&&a[t2]==0)));
}
