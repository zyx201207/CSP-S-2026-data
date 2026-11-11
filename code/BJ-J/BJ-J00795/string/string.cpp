#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[201010],ans,all;
char c[201010];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        all+=a[i];
    }
    int num=0,jl1=0,jl2=0,l=1,r=n;
    while(num!=all/2){
        if(l==r){
            break;
        }
        if(!jl1){
            if(num+a[l]>all/2)jl1=all/2-num;
            else jl1=a[l];
        }
        if(!jl2){
            if(num+a[r]>all/2)jl2=all/2-num;
            else jl2=a[r];
        }
        //cout<<jl1<<" "<<jl2<<"\n";
        if(jl1>jl2){
            //cout<<1;
            if(c[l]==c[r]){
                num+=jl2;
            }
            else{
                ans+=jl2;
                num+=jl2;
            }
            jl1=jl1-jl2;
            jl2=0;
            r--;
        }
        else if(jl1<jl2){
            //cout<<2;
            if(c[l]==c[r]){
                num+=jl1;
            }
            else{
                ans+=jl1;
                num+=jl1;
            }
            jl2=jl2-jl1;
            jl1=0;
            l++;
        }
        else{
           // cout<<3;
            if(c[l]==c[r]){
                num+=jl1;
            }
            else{
                ans+=jl1;
                num+=jl1;
            }
            jl1=0;
            jl2=0;
            l++;
            r--;
        }
    }
    cout<<ans;
    return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
