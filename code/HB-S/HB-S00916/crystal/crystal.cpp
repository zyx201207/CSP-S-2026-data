#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+7;
const int all=1e8;
int n,ans;
long long a[maxn],m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    if(n<=5000){
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        int sum=0;
        int num;
        for(int i=2;i<=n;i++){
            num=i;
            int u=a[i]-a[i-1];
            sum+=u*(i-1);
            int x=1,o=sum;
            while(o>m){
                o-=a[i]-a[x];
                x++,num--;
            }
            if(num>ans)ans=num;
        }
        cout<<ans;
    }
    if(n>5000){
        if(m>=all){
            for(int i=1;i<=n;i++)cin>>a[i];
            long long y=a[2]-a[1],z=0,x=0;
            while(m>z){
                x++;
                z+=y;
            }
            cout<<x-1;
        }
    }
    return 0;
}
