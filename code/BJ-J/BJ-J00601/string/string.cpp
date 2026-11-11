#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin>>n;
    ll a[200005];
    char c[200005];
    long long sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    ll p=1,q=n;
    ll tmp = sum/2;
    ll cnt=0;
    ll ans=0;
    while(p<q && cnt<tmp){
        if(c[p]!=c[q]){
            if(a[p]<a[q]){
                cnt+=a[p];
                a[q]-=a[p];

                ans+=a[p];
                p++;


            }
            else if(a[p]==a[q]){
                cnt+=a[p];
                ans+=a[p];
                p++;

                q--;


            }else{
                ans+=a[q];
                a[p]-=a[q];
                q--;

            }
        }if(c[p]==c[q]){
            if(a[p]<a[q]){
                cnt+=a[p];
                a[q]-=a[p];
                p++;



            }else if(a[p]==a[q]){
                cnt+=a[p];
                p++;

                q--;

            }else{
                a[p]-=a[q];
                q--;


            }
        }
    }
    cout<<ans;
    /*ll tmp=sum/2;
    ll cnt=0;
    map<char,ll> m1;
    map<char,ll> m2;
    //cout<<tmp<<endl;
    for(int i=1;cnt<tmp;i++){
        if(tmp-cnt<a[i]){
            m1[c[i]]+=tmp-cnt;
        }
        else m1[c[i]]+=a[i];
        if(a[i]<tmp-cnt) cnt+=a[i];
        else cnt=tmp;


    }
    cnt=0;
    for(int i=n;cnt<tmp;i--){
        if(tmp-cnt<a[i]){
            m2[c[i]]+=tmp-cnt;
        }
        else m2[c[i]]+=a[i];
        if(a[i]<tmp-cnt) cnt+=a[i];
        else cnt=tmp;


    }//cout<<cnt<<endl;
    /*ll ans1=0,ans2=0;
    for(auto it:m1){
        ans1+=abs(it.second-m2[it.first]);
    }for(auto it:m2){
        ans2+=abs(it.second-m1[it.first]);
    }
    for(char i='a';i<='z';i++){
        ans1+=abs(m1[i]-m2[i]);
    }
    if(ans1>=ans2){
        cout<<ans1;
    }else cout<<ans2;*/
    //cout<<ans1/2;

    return 0;
}
