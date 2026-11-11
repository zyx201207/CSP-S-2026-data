#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005],m,p,sum=0,sa[500005],ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sum/=n;
    //cout<<"sum:"<<sum<<endl;
    sort(a+1,a+n+1);
    int j;
    for(int i=1;i<=n;i++){
        sa[i]=a[i]-a[i-1];
        if(a[i]<n&&a[i+1]>n){
            if(sum-a[i]<a[i+1]-sum){
                p=a[i];
                j=i;
            }else{
                p=a[i+1];
                j=i+1;
            }
            break;
        }
    }
    //cout<<"p:"<<p<<" "<<"j:"<<j<<endl;
    int i=j+1,k=j-1;
    for(int l=1;l<=n;l++){
        int x=a[i]-p,y=p-a[k];
        if(x>=y){
            if(k==0){
                continue;
            }
            m-=y;
            if(m<0){
                break;
            }
            ans++;
            k--;
        }else{
            if(i==n+1){
                continue;
            }
            if(m-x<0){
                break;
            }
            m-=x;
            ans++;
            i++;
        }
    }
    cout<<ans;
    return 0;
}
