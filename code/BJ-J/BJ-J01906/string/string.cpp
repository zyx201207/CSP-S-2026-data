#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,a[N];
char c[N],tmp[5];
ll ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%s",&a[i],tmp);
        c[i]=tmp[0];
    }
    int j=n,x=a[n];
    for(int i=1;i<=n&&i<j;i++){
        int now=0;
        while(now<a[i]&&i<j){
            if(c[j]!=c[i]){
                if(now+x<=a[i]){
                    now+=x,ans+=x;
                    j--; x=a[j];
                }
                else{
                    ans+=a[i]-now;
                    x-=a[i]-now;
                    now=a[i];
                }
            }
            else{
                if(now+x<=a[i]){
                    now+=x;
                    j--; x=a[j];
                } 
                else{
                    x-=a[i]-now;
                    now=a[i];
                }
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}