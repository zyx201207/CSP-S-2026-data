#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],b[N],c[N],d[N];
bool check(int i,int k){
    return (i-k+1)*a[i]-(d[i]-d[k-1])>m;
}
void output(){
    for(int i = 2;i <= n;i++){
        for(int k = 1;k < i;k++){
            cout << (i-k+1)*a[i]-(d[i]-d[k-1]) << " ";//(c[i]-c[k]-a[i]*(k-1)+d[k-2])
        }
        cout << endl;
    }
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >>m;
    for(int i = 1;i <= n;i++)cin >> a[i];
    sort(a+1,a+1+n);
    //int base=a[1];
    //for(int i = 1;i <= n;i++)cout << a[i] << " ";
    b[1]=0;
    for(int i = 1;i <= n;i++){
        b[i]=a[i]-a[i-1];
        //c[i]=(i-1)*b[i]+c[i-1];
        d[i]=d[i-1]+a[i];
        //cout << d[i] <<"\n";
        //cout << b[i] << " " << c[i] << " \n";
    }
    //output();
    int ans=0,last=0;
    for(int i = 1;i <= n;i++){
        if(b[i]==0){
            last++;
            //cout << last << endl;
            ans=max(ans,last);
            continue;
        }
        int l = 1,r = i,mid=0;
        while(l<r){
            mid=(l+r)>>1;
            if(check(i,mid))l=mid+1;
            else r=mid;
            //cout << l << " " << r << endl;
        }
        int x=l;last=i-x+1;
        ans=max(ans,i-x+1);
        //cout << " " << last << endl;
    }
    cout << ans;
    return 0;
}
/*
5 5
1 2 4 8 9
*/
