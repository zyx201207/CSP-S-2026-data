#include<bits/stdc++.h>
using namespace std;
long long a[105];
int f(int n){
    int t;
    for(int i=1;i<=30;i++){
        if(n<=a[i]){
            t=i;
        }
    }
    int cnt=0;
    for(int i=t;i>=1;i--){
        if(n/a[i]==1){
            n%=a[i];
            cnt++;
        }
    }
    return cnt;
}
struct node{
    int b,h;
}s[100006];
bool cmp(node a,node b){
    return a.h<b.h;
}
int main(){
    freopen("and.in","r",stdin);
    freopen ("and.out","w",stdout);
    a[1]=1;
    for(int i=2;i<=30;i++){
        a[i]=a[i-1]*2;
    }
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i].b;
        s[i].h=f(s[i].b);
    }
    if(m==1){
        cout<<0<<endl;
        return 0;
    }
    if(m==n){
        int ttt=s[1].b;
        for(int i=2;i<=n;i++){
            ttt&=s[i].b;
        }
        cout<<ttt;
        return 0;
    }
    sort(s+1,s+1+n,cmp);
    int sum=s[n].b;
    m--;
    for(int i=n-1;i>=1;i--){
        if(m>0){
            sum&=s[i].b;
            m--;
        }
    }
    cout<<sum;
}
