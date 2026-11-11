#include <bits/stdc++.h>
using namespace std;

int a,b,e,f,ans1=1,ans2=1,ans3=1,ans4=1;
char c,d;

signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>e>>c>>b>>f>>d;
    if (a!=b) ans1=ans2=ans3=ans4=0;
    else if (e!=f) ans2=ans3=ans4=0;
    else if (c<='C'&&d>='D') ans3=ans4=0;
    else if (c>='D'&&d<='C') ans3=ans4=0;
    else if (c=='A'&&d=='C') ans4=0;
    else if (c=='C'&&d=='A') ans4=0;
    cout<<ans1<<ans2<<ans3<<ans4;
    return 0;
}
