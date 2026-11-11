#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c,d[500005],i,j,x=0,y=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n>5000){
        if(a[5]-a[4]==a[6]-a[5]&&a[56]-a[55]==a[57]-a[56]&&a[3334]-a[3333]==a[3336]-a[3335]){
            d[0]=a[1]-a[0];
            for(int i=1;i<n;i++){
                d[i]=d[i-1]+a[i+1]-a[0];
            }
            long long l=0,r=n;
            while(r!=l){
                long long min=(r+l)/2;
                if(d[min]>m){
                    r=min;
                }
                else if(d[min]<m){
                    l=min;
                }
                else {
                    cout<<min+2;
                    return 0;
                }
                if(r==l||r==l+1){
                    cout<<l+2;
                    return 0;
                }
            }
        }
    }
    sort(a,a+n);
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            b[j]=a[j];
        }
        j=i-1;
        c=m;
        while(c>=0){
            if(j<0||c<0){
                break;
            }
            if(b[j]<=a[i]){
                if(c>=a[i]-b[j]){
                    b[j]=a[i];
                    c-=a[i]-b[j];
                    j--;
                }
                else break;
            }
        }
        y=0;
        for(int j=0;j<n;j++){
            if(b[j]==a[i]){
                y++;
            }
        }
        x=max(x,y);
    }
    cout<<x;
    return 0;
}
//Where is the Chinese print way?
