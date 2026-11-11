#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m,a[2000010],s[2000010],d[2000010],ans;
__int128 f[2000010];
map<__int128,int> mp;
void print(__int128 x){
    if(x==0)return;
    print(x/10);
    cout<<(int)(x%10);
}
int main(){
    freopen("migrate.in","r",stdin);//***********************************************************
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        //cout<<t<<endl;
        cin>>n>>m;
        ans=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(c==11||c==12){
            for(int i=4;i<=n;i+=2){
                if((i/2)*(a[2]-a[1])<=m&&(i/2+1)*(a[2]-a[1])>m)ans+=n-i+1;
            }
            cout<<ans<<'\n';
            continue;
        }
        for(int i=1;i<=n;i++){
            //mp.clear();
            s[i]=0,d[0]=i;
            int lst=i,sum=1;
            for(int j=i+1;j<=n;j++){
                if(a[j]-a[lst]>m)lst=j-1,d[sum]=lst,sum++;
                s[j]=sum;
                //cout<<s[j]<<" ";
            }
            int l=i,r=i-1;
            f[i]=1;
            __int128 now=0;
            for(int j=i+1;j<=n;j++){
                if(s[j]!=s[j-1]){
                    while(r!=d[s[j-1]]){
                        ++r;
                        now+=f[r];
                        //mp[f[r]]++;
                        /*print(f[r]);
                        print(mp[f[l]]);
                        cout<<"*"<<endl;*/
                    }
                }
                while(a[j]-a[l]>m){
                    now-=f[l];
                    //mp[f[l]]--;
                    /*
                    print(f[l]);
                    print(mp[f[l]]);
                    cout<<"&"<<endl;*/
                    l++;
                }
                f[j]=now;
                //cout<<(now%2==0);
                if(now==2)ans++;
                //mp[now]++;
                //print(now);
            }
            //cout<<endl;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
0 1
4 2
1 2 3 4
*/
