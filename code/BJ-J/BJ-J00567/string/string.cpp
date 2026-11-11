#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,ans;
long long a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    long long l=1,r=n;
    while(l<r){
        long long minn,maxx;
        if(a[l]>a[r]){
            minn=r;
            maxx=l;
        }
        else{
            minn=l;
            maxx=r;
        }
        if(c[minn]!=c[maxx]){
            ans+=a[minn];
            if(a[minn]==a[maxx]){
                l++;
                r--;
            }
            else{
                a[maxx]-=a[minn];
                a[minn]=0;
                if(minn==l){
                    l++;
                }
                else if(minn=r){
                    r--;
                }
            }
        }
        else {
            if(a[minn]==a[maxx]){
                l++;
                r--;
            }
            else if(minn=r){
                a[maxx]-=a[minn];
                a[minn]=0;
                r--;
            }
            else if(minn=l){
                a[maxx]-=a[minn];
                a[minn]=0;
                l++;
            }
        }
    }
    cout<<ans;
    return 0;
}
