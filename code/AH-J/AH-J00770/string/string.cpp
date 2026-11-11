#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    char c;
    int x;
};
node a[200050];
int sum,t,ans,l,o;
int i,j;
int n;

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //freopen("string.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i].x>>a[i].c;
        l=l+a[i].x;
    }
    j=n;
    for(i=1;i<=n;i++){
        if(t>l/2){
            break;
        }
        while(a[i].x>0&&j>=1){
            o=min(a[j].x,a[i].x);
            if(a[i].c!=a[j].c){
                ans=ans+o;
            }
            a[j].x=a[j].x-o;
            t=t+o;
            a[i].x=a[i].x-o;
            //cout<<a[i].x<<endl;
            if(a[j].x==0) j--;
            if(t>=l/2){
                break;
            }
        }
        /*
        cout<<i<<" "<<j<<" "<<t<<endl;

        for(int _=1;_<=n;_++){
            cout<<a[_].x<<" ";
        }
        cout<<endl;
        */
    }
    cout<<ans;
    return 0;
}
