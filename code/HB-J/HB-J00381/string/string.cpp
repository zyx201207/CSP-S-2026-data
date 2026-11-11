#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define LL long long
struct Node{
    LL nums;
    char str;
};
LL n,ans;
Node in[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(LL i=1;i<=n;i++){
        LL x;
        char y;
        cin>>x>>y;
        in[i].nums=x;
        in[i].str=y;
    }
    for(LL i=1,j=n;i<=j;){
        LL ix=in[i].nums,jx=in[j].nums;
        char iy=in[i].str,jy=in[j].str;
        //cout<<i<<" "<<j<<" "<<ans<<endl;
        //cout<<ix<<" "<<iy<<" "<<jx<<" "<<jy<<endl;
        if(ix>jx){
            if(iy==jy){
                in[i].nums-=in[j].nums;
                j--;
            }else{
                in[i].nums-=in[j].nums;
                ans+=in[j].nums;
                j--;
            }
        }else if(ix<jx){
            if(iy==jy){
                in[j].nums-=in[i].nums;
                i++;
            }else{
                in[j].nums-=in[i].nums;
                ans+=in[i].nums;
                i++;
            }
        }else{
            if(iy==jy){
                i++;
                j--;
            }else{
                ans+=in[i].nums;
                i++;
                j--;
            }
        }
        if(i==j){
            break;
        }
    }
    cout<<ans;
    return 0;
}
