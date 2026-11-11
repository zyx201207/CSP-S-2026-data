#include<bits/stdc++.h>
using namespace std;
long long m,ans=0,v;
long long a[500005],ac[500005],ac1[500005];
int n;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n-1;i++){
        ac[i]=a[i+1]-a[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            ac1[j]=ac[j];
        }
        v=1;
        long long msheng=m;
        int js=i;
        while(msheng>=0){
            if(ac1[js]*v<=msheng){
                msheng-=ac1[js]*v;
                ac1[js]=0;
                js++;
                v++;
            }
            else{
                break;
            }
            if(js>n-1){
                break;
            }

        }
        if(v>ans){
            ans=v;
        }
    }
    cout<<ans;
    return 0;
}
