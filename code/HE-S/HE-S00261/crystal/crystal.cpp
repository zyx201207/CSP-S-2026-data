#include<iostream>
#include<algorithm>
using namespace std;
int a[500002],c[500002];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    cin>>a[0];
    int A=a[0],bc;
    bool B=1;
    for(int i=1;i<n;++i){
        cin>>a[i];
        if(a[i]!=A){
            A=0;
        }
        if(i<2){
            bc=a[1]-a[0];
        }else if(a[i]-a[i-1]!=bc){
            B=0;
        }
    }
    if(m==0){
        cout<<0;
        return 0;
    }
    if(A){
        cout<<n;
        return 0;
    }
    if(B){
        int con=0;
        long long s=0;
        long long ne=bc;
        while(s+ne<=m){
            s+=ne;
            ne+=bc;
            con++;
        }
        if(con){
            ++con;
        }
        cout<<con;
        return 0;
    }
    sort(a,a+n);
    for(int i=0;i<n;++i){
        c[i]=a[n-1]-a[i];
    }
    int mx=0;
    for(int i=n-1;i>0;--i){
        long long s=0;
        int j=i-1,ans=0;
        while(s<m&&j>=0){
            ans++;
            s+=(c[j]-c[i]);
            --j;
        }
        if(ans>0){
            ++ans;
        }
        mx=max(mx,ans);
    }
    cout<<mx;
    return 0;
}
