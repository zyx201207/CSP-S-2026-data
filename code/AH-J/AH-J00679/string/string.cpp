#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2E5+10;
LL a[N];
char ch[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    LL n;
    cin>>n;
    for(LL i=1;i<=n;i++){
        cin>>a[i]>>ch[i];
    }
    LL i=1,j=n;
    LL ans=0;
    while(i<j){
        if(a[i]<a[j]){
            if(ch[i]!=ch[j]){
                ans+=a[i];
            }
            a[j]-=a[i];
            i++;
        }
        /*
        221
        122
        aabbc
        cbbaa
        2-1=1
        2==2
        |1-2|=1
        1+1=2
        ohhhhhhh

        */
        else if(a[i]==a[j]){
                if(ch[i]!=ch[j]){
                    ans+=a[i];
                }
                i++,j--;

        }else{
            if(ch[i]!=ch[j]){
                ans+=a[j];
            }
            a[i]-=a[j];
            j--;
        }
    }
    cout<<ans;
    return 0;
}
