#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    bool x=false,y=false,z=false,m=false;
    cin>>a>>b>>c>>d;
    int c1,c2;
    if (a[0]-'0'==0) c1=a[1]-'0';
    else c1=10+a[1]-'0';
    if (c[0]-'0'==0) c2=c[1]-'0';
    else c2=10+c[1]-'0';
    x=(c1==c2);
    if (x){
        int s1,s2;
        if (b[0]-'0'==0) s1=b[1]-'0';
        else s1=10+b[1]-'0';
        if (d[0]-'0'==0) s2=d[1]-'0';
        else s2=10+d[1]-'0';
        y=(s1==s2);
        if (y){
            int g1=b[2]-'0',g2=d[2]-'0';
            if ((g1>=17&&g1<=19)&&(g2>=17&&g2<=19)) z=true;
            if ((g1==20||g1==21)&&(g2==20||g2==21)) z=true;
            if (z){
                if ((g1==19||g1==20)&&(g2==19||g2==20)) m=false;
                else  if ((g1-g2==1)||(g2-g1==1)) m=true;

            }
        }
    }
    cout<<x<<y<<z<<m;
    return 0;
}
