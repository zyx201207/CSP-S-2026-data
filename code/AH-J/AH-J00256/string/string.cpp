#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n,a[200005],L;
char c[200005];
bool ji,od;
ll ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        L+=a[i];
    }
    ll mid;
    if(L%2==0){
        od=1;
        mid=L/2;
    }else{
        ji=1;
        mid=(L-1)/2;
    }
    //cout<<"mid"<<mid<<endl;
    ll lz=0,l=1,r=n;
    ll tmp=0;
    while(l<=r){
        if(lz+a[l]<=mid){
            lz+=a[l];
            ll len=a[l];
            //cout<<"lz"<<lz<<endl;
            //cout<<"ans"<<ans<<endl;
            if(tmp){
                if(c[r]!=c[l]){
                    ans+=tmp;
                    tmp=0;
                    r--;
                }
                len-=tmp;
            }
            //cout<<"ans"<<ans<<endl;
            //cout<<"len"<<len<<endl;
            while(len){
                //cout<<1;
                if(a[r]<=len){
                    len-=a[r];
                    if(c[l]!=c[r]){
                        ans+=a[r];
                    }
                    r--;
                }else{
                    tmp=a[r]-len;
                    if(c[l]!=c[r]){
                        ans+=len;
                    }
                    len=0;
                }
            }
            //cout<<endl;
            //cout<<"ans"<<ans<<endl;
        }else{
            //cout<<"else";
            ll len=mid-lz;
            if(tmp&&len!=0){
                if(c[r]!=c[l]){
                    ans+=tmp;
                    tmp=0;
                    r--;
                }
                len-=tmp;
            }
            while(r>=l){
                if(c[l]!=c[r]){
                    ans+=a[r];
                }
                r--;
            }
        }
        l++;
        //cout<<"ans"<<ans<<endl;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
