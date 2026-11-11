#include<bits/stdc++.h>
using namespace std;

int n,m,cnt;
long long a[500020],maxn=-1e12,minn=1e12,mid1,mid2;

bool sorting1(long long a,long long b){
    return abs(a-mid1)<abs(b-mid1);
}

bool sorting2(long long a,long long b){
    return abs(a-mid2)<abs(b-mid2);
}

int check1(long long x){
    sort(a+1,a+n+1,sorting1);
    int cnt=0;
    long long sum=m;
    for(int i=1;i<=n;i++){
        //cout << a[i] << ' ';
        if(sum-abs(x-a[i])>=0){
            sum-=abs(x-a[i]);
            cnt++;
        }
        else{
            break;
        }
    }
    //printf("check1--%lld,now cnt is %d\n",x,cnt);
    return cnt;
}

int check2(long long x){
    sort(a+1,a+n+1,sorting2);
    int cnt=0;
    long long sum=m;
    for(int i=1;i<=n;i++){
        //cout << a[i] << ' ';
        if(sum-abs(x-a[i])>=0){
            sum-=abs(x-a[i]);
            cnt++;
        }
        else{
            break;
        }
    }
    //printf("check2--%lld,now cnt is %d\n",x,cnt);
    return cnt;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        maxn=max(a[i],maxn);
        minn=min(a[i],minn);
    }
    if(minn<0){
        for(int i=1;i<=n;i++){
            a[i]-=minn;
        }
        maxn-=minn;
    }
    long long l=0,r=maxn;
    while(l<r){
        mid1=(l+r)>>1;
        mid2=mid1+1;
        //cout << l << ' ' << r << '\n';
        //cout << mid1 << ' ' << mid2 << '\n';
        if(check1(mid1)>check2(mid2)){
            r=mid2-1;
        }
        else if(check1(mid1)<check2(mid2)){
            l=mid1;
        }
        else{
            break;
        }
    }
    sort(a+1,a+n+1,sorting1);
    //cout << mid1 << '\n';
    for(int i=1;i<=n;i++){
        if(m-abs(mid1-a[i])>=0){
            m-=abs(mid1-a[i]);
            cnt++;
        }
        else{
            break;
        }
    }
    cout << cnt;
    return 0;
}
//1 1 2 3 5 8
