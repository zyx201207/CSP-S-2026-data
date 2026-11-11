#include <bits/stdc++.h>
#define int long long
using namespace std;
int c1,c2,s1,s2;
string s01,s02;
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')if(c=='-')f=-1,c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s01>>c2>>s02;
//    cout<<0<<0<<0<<0;
//    exit(0);
    s1=(s01[0]-'0')*10+s01[1]-'0';
    s2=(s02[0]-'0')*10+s02[1]-'0';
//    cout<<s01[3]<<' '<<s02[3];
//    exit(0);
    if(c1==c2){
        cout<<1;
        if(s1==s2){
            cout<<1;
            if((s01[2]>='A'&&s01[2]<='C')&&(s02[2]>='A'&&s02[2]<='C')){
                cout<<1<<(abs(signed(s01[2]-s02[2]))==1);
            }else if((s01[2]=='D'||s01[2]=='F')&&(s02[2]=='D'&&s02[2]=='F')){
                cout<<1<<1;
            }
            else cout<<0<<0;
        }else cout<<0<<0<<0;
    }else cout<<0<<0<<0<<0;
    return 0;
}
