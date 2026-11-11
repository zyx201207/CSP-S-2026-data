#include<bits/stdc++.h>
#define int long long
using namespace std;
int l,r,n;
const int maxn=2e5+10;
char c[maxn];int len[maxn];
signed main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>len[i]>>c[i];
    }
    int l=1,r=n;int ans=0;
    while(l<=r){
        //printf("l=%d,r=%d,lenl=%d,lenr=%d,cl=%c,cr=%c\n",l,r,len[l],len[r],c[l],c[r]);
        if(c[l]==c[r]){
            if(len[l]>len[r]){
                len[l]=len[l]-len[r];len[r]=0;r--;
                continue;
            }
            if(len[l]<len[r]){
                len[r]=len[r]-len[l];len[l]=0;l++;
                continue;
            }
            if(len[l]==len[r]){
                len[l]=0,len[r]=0;l++,r--;
                continue;
            }
        }
        else{
            if(len[l]>len[r]){
                ans+=len[r];
                len[l]=len[l]-len[r];len[r]=0;r--;
                continue;
            }
            if(len[l]<len[r]){
                ans+=len[l];
                len[r]=len[r]-len[l];len[l]=0;l++;
                continue;
            }
            if(len[l]==len[r]){
                ans+=len[l];
                len[l]=0,len[r]=0;l++,r--;
                continue;
            }
        }
    }
    cout<<ans;
    return 0;
}
