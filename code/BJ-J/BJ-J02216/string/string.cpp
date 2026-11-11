#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
long long n,a[200005],len,x,ans;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++){
        x++;
        cin>>a[x]>>c[x];
        len+=a[x];
        if(c[x]==c[x-1]){
            a[x-1]+=a[x];
            x--;
        }
    }long long mid=(len+1)/2,lsa;
    char lsc;
    for(long long i=1,s=1;i<=x;i++){
        s+=a[i];
        if(s>mid){
            lsa=s-mid;
            lsc=c[i];
            s-=a[i];
            a[i]=mid-s;
            i++,x++;
            for(;i<=x;i++){
                swap(a[i],lsa);
                swap(c[i],lsc);
            }break;
        }if(s==mid)break;
    }
    long long r=1,ra=1,l=1,la=1;
    while(ra<mid){
        if(c[x-r+1]!=c[l]){
            ans+=min(a[l],a[x-r+1]);
        }
        if(ra-1<la-1){
            ra+=a[r];
            r++;
        }else{
            la+=a[l];
            l++;
        }
    }cout<<ans;
    return 0;
}
