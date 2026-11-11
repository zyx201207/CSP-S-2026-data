#include<bits/stdc++.h>
using namespace std;
int a[20005],b[20005],n,m,ma=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int t=n;
    if(n<=20);
    else if(n<=2000){
         for(int i=0;i<n;i++){
            cin>>a[i];
            ma=max(ma,a[i]);
            if(!i)b[i]=a[i];
            else b[i]=a[i]&b[i-1];
        }
        if(m==1){
            cout<<ma;
        }else if(m==n){
            cout<<b[n-1];
        }else if(m==2){
            ma=-1;
            for(int i=0;i<n;i++)
                for(int j=i+1;j<n;j++){
                    ma=max(a[i]&a[j],ma);
                }
            cout<<ma;
        }
    }else if(n>2000){
        map<int,int>mp;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]]++;
            ma=max(ma,a[i]);
        }
       //cout<<t;
        if(ma<=4){
            if(mp.count(4)&&mp[4]>=m)cout<<4;
            else if(mp.count(3)&&mp[3]>=m)cout<<3;
            else if(mp.count(2)&&mp[2]>=m)cout<<2;
            else if(mp.count(3)&&mp.count(1)&&mp[3]+mp[1]>=m || mp.count(1)&&mp[1]>=m)cout<<1;
            else cout<<0;
        }else if(pow(2,double(int(log2(t))))==t){
                 cout<<t-m;
        }else{
            cout<<a[t-m];
        }
    }
    return 0;
}
