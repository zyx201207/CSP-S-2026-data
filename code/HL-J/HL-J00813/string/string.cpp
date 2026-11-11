#include<bits/stdc++.h>
using namespace std;
int n;
const int N=2e5+1000;
long long a[N],len[N],ans,l,r;
typedef long long ll;
char c[N];
string s;
int main( ){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        len[i]=len[i-1]+a[i];
    }
    if(len[n]%2==0){
        l=len[n]/2;
        r=l+1;
    }else{
        l=len[n]/2;
        r=l+2;
    }
    auto itr=lower_bound(len+1,len+n+1,r)-len;
    auto itl=upper_bound(len+1,len+n+1,l)-len-1;
    int le=l-len[itl-1],ri=len[itr]-r+1;
    while(itl!=0&&itr!=n+1){
        if(le>ri){
            if(c[itl]==c[itr]){
                le=le-ri;
                itr++;
                ri=a[itr];
                continue;
            }
            ans+=ri;
            le=le-ri;
            itr++;
            ri=a[itr];
            continue;
        }
        if(le<ri){
            if(c[itl]==c[itr]){
                ri=ri-le;
                itl--;
                le=a[itl];
                continue;
            }
            ans+=le;
            ri=ri-le;
            itl--;
            le=a[itl];
            continue;
        }
        if(c[itl]!=c[itr]) ans+=le;
        itl--;
        itr++;
        le=a[itl];
        ri=a[itr];
    }
    cout<<ans;
    return 0;
}
