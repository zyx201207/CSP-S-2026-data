#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int n,m;

struct node{
    int a,b,c;
}a[N];

int ma1(int x){
    int cnt=0,res=0;
    while(x){
        if(x&1){
            res=max(res,cnt);
        }
        x>>=1;
        ++cnt;
    }
    return res;
}

int get1(int x){
    int cnt=0;
    while(x){
        if(x&1){
            cnt++;
        }
        x>>=1;
    }
    return cnt;
}

bool cmp(node a,node b){
    if(a.b==b.b){
        return a.c>b.c;
    }
    return a.b>b.b;
}

void Main1(){
    int ans=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i==j){
                continue;
            }
            ans=max(ans,a[i].a&a[j].a);
        }
    }
    cout<<ans<<endl;
}

void Main2(){
    int ans=a[n].a;
    int i=n-1;
    while(m--){
        ans&=a[i].a;
        --i;
    }
    cout<<ans<<endl;
}

bool ch(int x){
    while(x){
        if(x%2==1){
            return false;
        }
        x>>=1;
    }
    return true;
}

void Main3(){
    cout<<a[m].a<<endl;
}

int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    bool f=true,t=true;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i].a;
        if(!ch(a[i].a+1)){
            t=false;
        }
        if(a[i].a!=a[i-1].a+1){
            if(i==1){
                continue;
            }
            f=false;
        }
        a[i].b=get1(a[i].a);
        a[i].c=ma1(a[i].a);
    }
    if(f==true){
        Main2();
        return 0;
    }
    if(m==2){
        Main1();
        return 0;
    }
    sort(a+1,a+n+1,cmp);

    if(t){
        Main3();
        return 0;
    }

    int ans=a[1].a;
    for(int i=2;i<=m;++i){
        ans&=a[i].a;
    }
    cout<<ans<<endl;

    return 0;
}
