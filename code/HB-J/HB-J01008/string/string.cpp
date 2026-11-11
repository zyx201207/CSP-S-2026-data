#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,c,len=0,s=0,ans=0;
    string d,a;
    /*len[0]=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c>>d[i];
        //cout<<endl<<'a'<<endl;
        len[i]=len[i-1]+c;
    }
    s=len[n];
    long long r,l,mid,last=n;
    for(int i=1;i<=n;i++){
        r=max(n/2,last);
        l=min(last,n/2);
        while(l<r){
            mid=(l+r)/2;
            //cout<<l<<' '<<r<<' '<<mid<<endl;
            if(len[mid]<s-len[i]+1){
                l=mid+1;
            }else if(len[mid]>s-len[i]+1){
                r=mid;
            }else if(len[mid]==s-len[i]+1){
                l=r=mid+1;
                break;
            }
        }
        last=r;
        if(d[r]!=d[i]){
            ans+=(len[i]-len[i-1]);
        }
    }
    cout<<ans/2;*/
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c>>a;
        for(int j=0;j<c;j++){
            d+=a;
        }
    }
    for(int i=0;i<d.length();i++){
        if(d[i]!=d[d.length()-i-1])ans++;

    }
    cout<<ans/2;
    return 0;
}
