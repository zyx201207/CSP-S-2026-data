#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    int c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int a[18]{0},b[18]{0},c[18]{0},d[18]{0},f[18]{0};
    int n=0;
    for(int i=1;i<18;i++)
        {
            int zf='A',sz=01;
            a[i]=sz+zf;
            sz+=1;
        }
    for(int i=1;i<18;i++)
        {
            int zf='B',sz=01;
            b[i]=sz+zf;
            sz+=1;
        }
    for(int i=1;i<18;i++)
        {
            int zf='C',sz=01;
            c[i]=sz+zf;
            sz+=1;
        }
    for(int i=1;i<18;i++)
        {
            int zf='D',sz=01;
            d[i]=sz+zf;
            sz+=1;
        }
    for(int i=1;i<18;i++)
        {
            int zf='F',sz=01;
            f[i]=sz+zf;
            sz+=1;
        }

    if(c1==c2)
        n+=1;
        for(int i=1;i<18;i++)
        {
            if(s1==a[i] && s2==b[i] || s1==a[i] && s2==c[i] || s1==a[i] && s2==d[i] || s1==a[i] && s2==f[i] || s1==b[i] && s2==c[i] || s1==b[i] && s2==d[i] || s1==b[i] && s2==f[i] || s1==c[i] && s2==d[i] || s1==c[i] && s2==f[i] || s1==d[i] && s2==f[i])
                n+=1;
                if(s1==a[i] && s2==b[i] || s1==a[i] && s2==c[i] || s1==b[i] && s2==c[i] || s1==d[i] && s2==f[i])
                    n+=1;
                    if(s1==a[i] && s2==b[i] || s1==b[i] && s2==c[i] || s1==d[i] && s2==f[i])
                        n+=1;
        }
    if(c1!=c2)
        cout<<"0000";

    if(n==4)
        cout<<"1111";
    else if(n==3)
        cout<<"1110";
    else if(n==2)
        cout<<"1100";
    else if(n==1)
        cout<<"1000";
    else if(n==0)
        cout<<"0000";

    return 0;
}
