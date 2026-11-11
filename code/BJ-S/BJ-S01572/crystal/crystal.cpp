#include<bits/stdc++.h>
using namespace std;
    long long n,m;
    int a[500005];
    long long ans;

    long long b[500005];
    long long c[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long f=-1000000000000;
    long long place;
        for(int i=0;i<n;i++){
              for(int j=0;j<n;j++){
                  if(f<a[j]){
                    f=a[j];
                    place=j;
                  }
    }
    b[i]=f;
    a[place]=1000000000000;
    f=-1000000000000;
    }int i=0;
    for(int j=n-1;j>-1;j--){
         c[i]=b[j];
i++;
    }





int num=0,ans=0;
for(int i=0;i<n;i++){
    for(int j=0;j<i-1;j++){
        num+=c[i]-c[j];

        }        if(num>m){
            cout<<i;return 0;
            num=0;ans=0;
    }
}
return 0;
}
