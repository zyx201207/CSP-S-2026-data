#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define int long long
vector<int> z;
vector<char> x;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int sum=0;
    z.push_back(0);
    x.push_back(' ');
    for(int i=1;i<=n;i++){
        int q;
        char w;
        cin>>q>>w;
        z.push_back(q);
        x.push_back(w);
        //cin>>z[i];
        //cin>>x[i];
        sum+=z[i];
    }
    int zz1=1,zz2=n,xx1=1,xx2=n;
    int z1=z[1],z2=z[n];
    char x1=x[1],x2=x[n];
    int ans=0;
    while(zz1<zz2){
        if(x1==x2){
            if(z1>=z2){
                z1-=z2;
                z2-=z2;
            }else{
                z2-=z1;
                z1-=z1;
            }
        }else{
            if(z1>=z2){
                ans+=z2;
                z1-=z2;
                z2-=z2;
            }else{
                ans+=z1;
                z2-=z1;
                z1-=z1;
            }
        }
        if(z1<=0){
            zz1++;
            z1=z[zz1];
            x1=x[zz1];
        }
        if(z2<=0){
            zz2--;
            z2=z[zz2];
            x2=x[zz2];
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
