#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=5e5+5;

int n,m;
ll a[MAXN];
ll f[MAXN];
int ans=1;
bool cmp(int x,int y){
    return x<y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        f[i]=a[i+1]-a[i];
    }
    int flag=0;
    for(int i=2;i<=n;i++){
        if(f[i]!=f[i-1])flag=1;
    }
    if(flag==0){
        int num=0;
        ans=1;
        for(ll j=1;j<=n;j++){
			if(num+j*f[1]<=m){
				num=num+j*f[1];
				ans++;
			}else break;
        }
        cout<<ans;
        return 0;
    }
    
    for(ll i=1;i<=n;i++){
        int num=0,flag=1;
        for(ll j=i;j<=n;j++){
            num+=flag*f[i];
            if(num>m)break;
            ++flag;
        }ans=max(ans,flag);
    }cout<<ans;
    
    return 0;
}

/*
T1 75pts(1~19)
for every points 
it add forward and can't back;
sort +ans
if point i its do j times 
it need to a(i+j)*(j-i+1)
its O(n^2)--8~9 
we 
5 8
-3 -1 2 2 7
+5 +3
2  2  2 2 7
5 3
-1 -1  -1  8  8 9
       +1 +1 +1


*/
