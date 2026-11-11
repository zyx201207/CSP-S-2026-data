#include<bits/stdc++.h>
using namespace std;
int op[500005];
struct stu{
    int k;
    int a[500005];
    int t[500005];
}s[505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>op[i];
    for(int i=1;i<=n;i++){
        cin>>s[i].k;
        for(int j=1;j<=s[i].k;j++){
            cin>>s[i].a[j]>>s[i].t[j];
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        long long cnt=op[x]+op[y];
        if(n==1){
            for(int i=1;i<=s[1].k;i++){
                if(s[1].a[i]==x||s[1].a[i]==y)
                {
                    cnt+=s[1].t[i];
                }
            }if(q!=0)
                cout<<cnt<<endl;
            else
                cout<<cnt;
            continue;
        }
        else if(n==2){
            int flag=0;
            int f1=0,f2=0,f3=0,f4=0;
            int u1=0,u2=0,u3=0,u4=0;
            long long cnt1=cnt;
            for(int i=1;i<=s[1].k;i++){
                if(s[1].a[i]==x||s[1].a[i]==y){
                    flag++;
                    cnt1+=s[1].t[i];
                }
                if(s[1].a[i]==x){
                    f1=1;
                    u1=i;
                }
                if(s[1].a[i]==y){
                    f2=1;
                    u2=i;
                }
            }
            long long cnt2=cnt;
            for(int i=1;i<=s[2].k;i++){
                if(s[2].a[i]==x||s[2].a[i]==y){
                    flag++;
                    cnt2+=s[2].t[i];
                }
                if(s[2].a[i]==x){
                    f3=1;
                    u3=i;
                }
                if(s[2].a[i]==y){
                    f4=1;
                    u4=i;
                }
            }
            if(f1==1&&f2==1&&f3==0&&f4==0){
                if(q!=0)
                cout<<cnt1<<endl;
                else
                cout<<cnt1;
                continue;
            }
            if(f1==0&&f2==0&&f3==1&&f4==1){
                if(q!=0)
                cout<<cnt2<<endl;
                else
                cout<<cnt2;
                continue;
            }
            int _min=1000000000;
            for(int i=1;i<=s[1].k;i++){
                for(int j=1;j<=s[2].k;j++){
                    if(s[1].a[i]==s[2].a[i]){
                        _min=min(_min,s[1].t[i]+s[2].t[j]);
                    }
                }
            }cnt+=_min;
            if(f1==1&&f2==1&&f3==1&&f4==1){
                cout<<min(min(cnt1,cnt2),min(cnt+s[1].t[u1]+s[2].t[u4],cnt+s[1].t[u4]+s[2].t[u3]));
                if(q!=0)cout<<endl;
                continue;
            }
            if(f1==1&&f2==1&&f3==0&&f4==1){
                cout<<min(cnt1,cnt+s[1].t[u1]+s[2].t[u4]);
                if(q!=0)cout<<endl;
                continue;
            }
            if(f1==1&&f2==1&&f3==1&&f4==0){
                cout<<min(cnt1,cnt+s[1].t[u2]+s[2].t[u3]);
                if(q!=0)cout<<endl;
                continue;
            }
            if(f1==1&&f2==0&&f3==1&&f4==1){
                cout<<min(cnt2,cnt+s[1].t[u1]+s[2].t[u4]);
                if(q!=0)cout<<endl;
                continue;
            }
            if(f1==0&&f2==1&&f3==1&&f4==1){
                cout<<min(cnt2,cnt+s[1].t[u2]+s[2].t[u3]);
                if(q!=0)cout<<endl;
                continue;
            }
            if(f1==1&&f2==0&&f3==0&&f4==1){
                cout<<cnt+s[1].t[u1]+s[2].t[u4];
                if(q!=0)cout<<endl;
                continue;
            }
            if(f1==0&&f2==1&&f3==1&&f4==0){
                cout<<cnt+s[1].t[u2]+s[2].t[u3];
                if(q!=0)cout<<endl;
                continue;
            }
        }
    }
    return 0;
}
