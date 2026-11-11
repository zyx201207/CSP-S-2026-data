#include <bits/stdc++.h>
using namespace std;
const long long N=2000000+7;
long long  n;
long long a[N];
char b[N];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("string5.in","r",stdin);
    freopen("string5.out","w",stdout);
    cin>>n;
    long long cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        cnt+=a[i];
    }
        long long d=(cnt+1)/2;
        long long t=0;
        char c;
        for(int i=1;i<=n;i++){
            d-=a[i];
            if(d==0||d<0){
                t=i;
                c=b[i];
                break;
            }
        }
        long long s1=0,s2=0;
        for(int i=1;i<=t-1;i++){
            if(c!=b[i]){
            s1+=a[i];
            }
        }
        for(int i=t+1;i<=n;i++){
            if(c!=b[i]){
            s2+=a[i];
            }
        }
        if(s1>=s2){
            cout<<s1;
        }else{
            cout<<s2;
        }

    return 0;
}
