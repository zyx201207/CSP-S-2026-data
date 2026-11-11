#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+13;
int n;
struct str{int a;char ch;}f[N];
int sum,ans=0;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>f[i].a>>f[i].ch;
    for(int i=1;i<=n;i++)sum+=f[i].a;
    int i=1,j=n;
    str rem1,rem2;
    rem1.a=0,rem2.a=0;
    int cnt=0;//count how many char we have visited;
    while(i<j){
        if(rem1.a>0){
            if(rem1.a>f[j].a){
                if(rem1.ch!=f[j].ch)ans+=f[j].a;
                cnt+=f[j].a*2;
                rem1.a-=f[j].a;
                j--;
            }else{
                if(rem1.ch!=f[j].ch)ans+=rem1.a;
                cnt+=rem1.a*2;
                rem2.a=f[j].a-rem1.a;
                rem2.ch=f[j].ch;
                rem1.a=0;
                i++;
                if(rem2.a==0)j--;
            }
        }
        if(rem2.a>0){
            if(rem2.a>f[i].a){
                if(rem2.ch!=f[i].ch)ans+=f[i].a;
                cnt+=f[i].a*2;
                cnt+=rem2.ch;
                rem2.a-=f[i].a;
                i++;
            }else{
                if(rem2.ch!=f[i].ch)ans+=rem2.a;
                cnt+=rem2.a*2;
                rem1.a=f[i].a-rem2.a;
                rem1.ch=f[i].ch;
                rem2.a=0;
                j--;
                if(rem1.a==0)i++;
            }
        }
        if(rem2.a==0&&rem1.a==0&&i!=j){
            if(f[i].a>f[j].a){
                if(f[i].ch!=f[j].ch)ans+=f[j].a;
                cnt+=f[j].a*2;
                rem1.ch=f[i].ch;
                rem1.a=f[i].a-f[j].a;
                j--;
            }else{
                if(f[i].ch!=f[j].ch)ans+=f[i].a;
                cnt+=f[i].a*2;
                rem2.ch=f[j].ch;
                rem2.a=f[j].a-f[i].a;
                i++;
                if(rem2.a==0)j--;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
