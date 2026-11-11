#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N];
int n;
long long m;
int maxnum;

void f(int l,int r){
    if(l>r){
        return;
    }
    int mid=(l+r)>>1;
    int loc=mid;
    long long cnt=0;

    for(int i=loc;i>0;i--){
        cnt=cnt+(a[loc]-a[i]);
        if(cnt==m){
            maxnum=max((loc-i+1),maxnum);
            return;
        }
        if(cnt>m){
            int num=loc-i;
            maxnum=max(maxnum,num);
            return;
        }
    }

    f(l,mid);
    f(mid,r);
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    long long l=0;
    long long r=0;
    bool flag=1;
    bool ch=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=a[1]){
            flag=0;
        }
        if(i!=1 && (a[i]-a[i-1]!=a[2]-a[1])){
            ch=0;
        }
    }
    if(flag==1){
        cout<<n;
        return 0;
    }
    if(ch==1){
        long long yu=a[2]-a[1];
        if(m<yu){
            cout<<0;
            return 0;
        }
        long long num=m/yu;
        cout<<num<<endl;
        long long ans=num/(a[n]+a[1])*2;
        cout<<ans;
        return 0;
    }
    sort(a+1,a+1+n);
    f(1,n);

    cout<<maxnum;

    return 0;

}
