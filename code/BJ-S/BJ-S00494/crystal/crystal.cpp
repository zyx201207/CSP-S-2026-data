#include<bits/stdc++.h>

using namespace std;

long long n,m;
long long lst[500005];
bool f1=1,f2=1;
long long mini=0x3f3f3f3f,maxi=-0x3f3f3f3f;
long long d;
void solve1(){
    long long ans=0;
    for(int i=1;i<=n;i++){
        long long cnt=1,sum=0;
        long long now=lst[i];
        for(int j=i-1;j>=1;j--){
            if(sum+(now-lst[j])>m){
                break;
            }
            sum+=(now-lst[j]);
            cnt++;
        }
        ans=max(ans,cnt);
    }

    cout<<ans;
}
void solve2(){
    //cout<<mini<<" "<<maxi<<'\n';
    long long ans=0;
    for(int i=mini;i<=maxi;i++){
        if(i==mini){
            ans=max(ans,1);
            continue;
        }
        int p=upper_bound(lst+1,lst+1+n,i)-lst-1;
        //cout<<i<<":"<<p<<'\n';
        long long sum=0,cnt=0;
        for(int j=p;j>=1;j--){
            if(sum+(i-lst[j])>m){
                break;
            }
            sum+=(i-lst[j]);
            cnt++;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
}
void solve3(){
    long long ans=0;
    for(int i=1;i<=n;i++){
        long long l=1,r=i;
        while(l<r){
            long long mid=l+r>>1;
            if(mid*(mid+1)/2LL<=m){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        ans=max(ans,l);
    }
    cout<<ans;
}
void solve4(){
    long long ans=0;
    for(int i=1;i<=n;i++){
        long long l=1,r=i;
        while(l<r){
            long long mid=l+r>>1;
            if(mid*(mid+1)*d/2LL<=m){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        ans=max(ans,l);
    }
    cout<<ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>lst[i];
        mini=min(mini,lst[i]);
        maxi=max(maxi,lst[i]);
        if(lst[i]!=i){
            f1=0;
        }
    }
    d=lst[2]-lst[1];
    for(int i=2;i<=n;i++){
        if(lst[i]-lst[i-1]!=d){
            f2=0;
        }
    }

    sort(lst+1,lst+1+n);


    if(n<=5000){
        solve1();
    }
    else if(-100<=mini && maxi<=100){
        solve2();
    }
    else if(f1){
        solve3();
    }
    else if(f2){
        solve4();
    }
    else{
        solve2();
    }

    return 0;
}
