#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,a[500005];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m<1000000000000000000){
        for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(a[i]>a[j]){
                swap(a[i],a[j]);
            }
        }
        }
        int maxx=1;
        for(int i=1;i<n;i++){
            int cnt=1;
            int sh=m;
            for(int j=0;j<i;j++){
                if(a[i]-a[j]<sh){
                    cnt++;
                    sh=sh-(a[i]-a[j]);
                }
            }
            maxx=max(maxx,cnt);
        }
        cout<<maxx+1;
    }
    else{
        int i=1,sum=1;
        int y=a[1]-a[0];
        while(sum<=m){
            i+=y;
            sum+=i;
        }
        cout<<i;
    }
    return 0;
}
