#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[200005];
int num(int a){
    int t=a;
    string s="";
    while(t>0){
        char y=(t%2)+'0';
        s=y+s;
        t/=2;
    }
    int ans=0;
    for(int i=0;i<s.size();++i){
        if(s[i]=='1')ans++;
    }
    return ans;
}
bool cmp(int x,int y){
    if(num(x)!=num(y))return num(x)>num(y);
    else return x>y;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m==1){
            int maxx=0;
        for(int i=1;i<=n;++i){
            cin>>a[i];
            maxx=max(maxx,num(a[i]));
        }
        cout<<maxx;
    }else if(m==n){
        cin>>a[1];
        int ans=a[1];
        for(int i=2;i<=n;++i){
            cin>>a[i];
            ans&=a[i];
        }
        cout<<ans;
    }else if(m==2){
        int max1=0;
        for(int i=1;i<=n;++i){
            cin>>a[i];
            max1=max(max1,num(a[i]));
        }
        int max2=0;
        for(int i=1;i<=n;++i){
            cin>>a[i];
            max2=max(max2,num(a[i]));
        }
        max1&=max2;
        cout<<max1;
    }else if(m==n-1){
        int minn=1e6;
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        sort(a+1,a+n+1,cmp);
        int ans=a[1];
        for(int i=2;i<=n-1;++i){
            ans&=a[i];
        }
        cout<<ans;
    }else{
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        sort(a+1,a+n+1,cmp);
        int ans=a[1];
        for(int i=2;i<=m;++i){
            ans&=a[i];
        }
        cout<<ans;
    }
    return 0;
}
