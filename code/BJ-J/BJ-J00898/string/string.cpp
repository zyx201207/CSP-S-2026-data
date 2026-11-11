#include<iostream>
#define int long long
using namespace std;
int p[200005];
char q[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        cin>>p[i]>>q[i];
    }
    int l=1,r=n;
    int cnt=0;
    while(l<r){
        if(p[l]>=p[r]){
            if(q[l]!=q[r]){
                cnt+=p[r];
            }
            p[l]-=p[r];
            p[r]=0;
            r--;
        }
        else if(p[l]<p[r]){
            if(q[l]!=q[r]){
                cnt+=p[l];
            }
            p[r]-=p[l];
            p[l]=0;
            l++;
        }
    }
    cout<<cnt;
    return 0;
}
