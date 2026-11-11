#include <bits/stdc++.h>
using namespace std;
int a[10005];
char b[10005];
int sum,cnt;
int ed,be;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >>n;
    for(int i=1;i <= n;i++)
    {
        cin >>a[i];
        sum += a[i];
        cin >>b[i];
    }
    be = 1,ed=n;
    for(int k=1,e = sum;k <= e;k++,e--)
    {
        if(b[k] != b[e])
            cnt++;
    }
    //while(ed!=be)
    //{
       // if(b[be] != b[ed])
        //{
       //     cnt += min(a[be],a[ed]);
      //  }
       // a[ed] -= min(a[be],a[ed]);
       // a[be] -= min(a[be],a[ed]);
       // if(a[ed] == 0)
        //    ed--;
       // if(a[be] == 0)
         //   be++;
   // }
    cout <<cnt;
    return 0;
}
