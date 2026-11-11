#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d,e="",f="";
    cin>>a>>b>>c>>d;
    e+=b[2];
    f+=d[2];
    b.erase(2);
    d.erase(2);
    if(e=="D")
        e="E";
    if(f=="D")
        f="E";
    cout<<(a==c)<<(a==c&&b==d)<<(a==c&&b==d&&(e<"D")==(f<"D"))<<(a==c&&b==d&&abs(e[0]-f[0])==1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
