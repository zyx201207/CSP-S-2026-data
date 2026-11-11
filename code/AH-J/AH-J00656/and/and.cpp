#include<iostream>
#include<algorithm>
using namespace std;
int n,m,s[200010],l=1,u;
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    cin>>s[i];
    sort(s,s+n,cmp);
    while(l<s[m-1])
        l*=2;
    for(int i=0;i<m;i++)
        s[i]=s[i]%l;
    sort(s,s+n,cmp);
    u=s[0];
    for(int i=1;i<m;i++)
        u=u&s[i];
    cout<<u<<endl;
    return 0;
}
